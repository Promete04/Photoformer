#include "TinyImageJM.hpp"

TinyImageJM::TinyImageJM(std::string p_name)
{
    internal_name = p_name;
    filePointer = nullptr;
    imageValid = false;
    internal_width = 0;
    internal_height = 0;
    internal_error = "";
    internal_image = nullptr;
    internal_palette = nullptr;   // palette data (if uses palette)
}

    bool TinyImageJM::isBMP()
    {
        std::string::size_type posOfDot = internal_name.find_last_of(".");
        std::string ext = internal_name.substr(posOfDot+1,std::string::npos);
        return ext.compare("BMP")==0 || ext.compare("bmp")==0 ||
        ext.compare("BmP")==0 || ext.compare("bmP")==0 ||
        ext.compare("BMp")==0 || ext.compare("bMp")==0 ||
        ext.compare("Bmp")==0 || ext.compare("bMP")==0;
    }
    
    bool TinyImageJM::openFile(std::string p_flags)
    {
    
        filePointer = fopen(internal_name.c_str(), p_flags.c_str());    // FILEFLAGS_READBINARY
        
        return filePointer != nullptr;
    }
    
    bool TinyImageJM::loadImageFromDisk()        /* returns isValid() */
    {
        if (isBMP())
        {
            if (openFile("rb"))
            {
                unsigned long padding =  internal_width%4;    // calculate padding to avoid those bytes
                unsigned char * palette = NULL;   // palette data (if uses palette)
                int sizePixelCount;   // pixel count
                short bit_count;   // bit count per pixel (24 if no palette)
                int color_count = 0;   // colors used (if uses palette)
                unsigned char temp;
                int countOfBytesRead = 0;
                
                
                fseek(filePointer, 18, SEEK_SET);
                fread(&internal_width, sizeof(int), 1, filePointer);    // read width
                fread(&internal_height, sizeof(int), 1, filePointer);   // read height
                
                fseek(filePointer, 28, SEEK_SET);
                fread(&bit_count, sizeof(short), 1, filePointer);    // read bit count 
                
                fseek(filePointer, 54, SEEK_SET);
                
                /* If uses palette (bit count is not 24) */
                if (bit_count != 24)
                    {
                        color_count = (int)pow(2.0, bit_count);
                        palette = (unsigned char *)malloc(sizeof(unsigned char) * 4 * color_count);
                        fread(palette, sizeof(unsigned char), 4 * color_count, filePointer);
                    }
                    
                /* Allocates memory for the image */
                sizePixelCount = internal_width * internal_height;
                internal_image = (unsigned char *)malloc(sizeof(unsigned char) * sizePixelCount * 3);
                
                /* Reads the image data */
                if (bit_count == 24)
                {
                    unsigned char paddingBytes[4]; // extra safety at 1 byte cost
                    paddingBytes[0]=0x00;
                    paddingBytes[1]=0x00;
                    paddingBytes[2]=0x00;
                    paddingBytes[3]=0x00;
                    
                    for (int i=0; i<internal_height; i++)
                    {
                        fread(internal_image+(i*internal_width*3),internal_width*3,1,filePointer);
                        fread(paddingBytes,padding,1,filePointer);  // read padding to ignore it
                    }
                }
                else
                {
                    while (countOfBytesRead < sizePixelCount)
                        {
                            fread(&temp, sizeof(unsigned char), 1, filePointer);
                            internal_image[countOfBytesRead * 3] = palette[temp * 4];
                            internal_image[countOfBytesRead * 3 + 1] = palette[temp * 4 + 1];
                            internal_image[countOfBytesRead * 3 + 2] = palette[temp * 4 + 2];
                            countOfBytesRead++;
                        }
                }
                
                fclose(filePointer);
                imageValid=true;
            }
            else
            {      
                imageValid=false;
                internal_error="File open failed";
            }
        }
        else
        {
            imageValid=false;
            internal_error="Not BMP";
        }
        
        return imageValid;
    }
    
    bool TinyImageJM::isValid()
    {
        return imageValid;
    }

    unsigned char * TinyImageJM::getImagePointertoInternal()
    {
        unsigned char * result = nullptr;
        if (imageValid)
        {
            result = internal_image;
        }
        
        return result;
    }

    int TinyImageJM::getWidth()
    {
        int result = 0;
        if (imageValid)
        {
            result = internal_width;
        }
        
        return result;
    }

    int TinyImageJM::getHeight()
    {
        int result = 0;
        if (imageValid)
        {
            result = internal_height;
        }
        
        return result;
    }
    
    std::string TinyImageJM::getInternalError()
    {
        return internal_error;
    }

    bool TinyImageJM::releaseImageMemory()
    {
        bool result = false;
        if (imageValid && internal_image!=nullptr)
        {
            free(internal_image);
            if (internal_palette!=nullptr)
            {
                free(internal_palette);
            }
            result = true;
        }

        return result;
    }
    
    void TinyImageJM::setNewImagePointerWithOldRemoval(unsigned char * p_image, int p_width, int p_height)
    {
        if (internal_palette!=nullptr)
            {
                free(internal_palette);
            }
        
        if (internal_image!=nullptr)
            {
                free(internal_image);
            }
            
        internal_image = p_image;
        internal_width = p_width;
        internal_height = p_height;
        imageValid = true;
    }
    
    int TinyImageJM::saveImageToDisk(std::string p_name)
    {
        int result=0;
        
        internal_name = p_name;
    
        /* Check if the file exists */
        if (openFile("rb"))
        {
            fclose(filePointer);
            result = -1;  // file exist, abort
        }
        else
        {
            if (openFile("wb"))
            {
                unsigned long padding =  internal_width%4; 
                //unsigned long paddingb =  (4 - (width*3 -((width*3/4) * 4)))%4; 
                //std::cout << "padding: " << padding << "          padding B: " << paddingb <<std::endl;
                
                unsigned char header[14];
                header[0] = 0x42; //'B';              
                header[1] = 0x4d; //'M';
                unsigned long fileSize_02 = (internal_width*3+padding) * internal_height + 54; // calcular data + header
                //std::cout << "file size: " << fileSize_02 <<std::endl;
                
                header[2] = fileSize_02 & 0xFF;
                header[3] = (fileSize_02 >> 8) & 0xFF;
                header[4] = (fileSize_02 >> 16) & 0xFF;
                header[5] = (fileSize_02 >> 24) & 0xFF;
                //std::cout << "file size: " << (int)header[2] << " . " << (int)header[3] << " . "<< (int)header[4] << " . " << (int)header[5] << std::endl;
                
                header[6] = 0;
                header[7] = 0;
                header[8] = 0;
                header[9] = 0;
                header[10] = 0x36; // offset to data, 54
                header[11] = 0;
                header[12] = 0;
                header[13] = 0;

                fwrite(header, 14, 1, filePointer);                

 
                unsigned char bitmapV5Header[40];
                bitmapV5Header[0] = 0x28;
                bitmapV5Header[1] = 0;
                bitmapV5Header[2] = 0;
                bitmapV5Header[3] = 0;
                unsigned long imageWidth_7 = (unsigned long)internal_width;
                bitmapV5Header[4] = imageWidth_7 & 0xFF;
                bitmapV5Header[5] = (imageWidth_7 >> 8) & 0xFF;
                bitmapV5Header[6] = (imageWidth_7 >> 16) & 0xFF;
                bitmapV5Header[7] = (imageWidth_7 >> 24) & 0xFF;
                unsigned long imageHeight_8 = (unsigned long)internal_height;
                bitmapV5Header[8] = imageHeight_8 & 0xFF;
                bitmapV5Header[9] = (imageHeight_8 >> 8) & 0xFF;
                bitmapV5Header[10] = (imageHeight_8 >> 16) & 0xFF;
                bitmapV5Header[11] = (imageHeight_8 >> 24)& 0xFF;
                bitmapV5Header[12] = 0x01;  // plane
                bitmapV5Header[13] = 0x00;  // plane
                bitmapV5Header[14] = 0x18;  // 24 bits
                bitmapV5Header[15] = 0x00;  // 24 bits
                
                bitmapV5Header[16] = 0x00;  // no compression
                bitmapV5Header[17] = 0x00;  // no compression
                bitmapV5Header[18] = 0x00;  // no compression
                bitmapV5Header[19] = 0x00;  // no compression
                
                unsigned long rawDataSize = (unsigned long)(internal_height * (internal_width*3+padding));
                //std::cout << "rawDataSize: " << rawDataSize <<std::endl;
                bitmapV5Header[20] = rawDataSize & 0xFF;  // data size
                bitmapV5Header[21] = (rawDataSize >> 8) & 0xFF;  // data size
                bitmapV5Header[22] = (rawDataSize >> 16) & 0xFF;  // data size
                bitmapV5Header[23] = (rawDataSize >> 24)& 0xFF;  // data size

                bitmapV5Header[24] = 0x13;  // hor resol
                bitmapV5Header[25] = 0x0B;  // hor resol
                bitmapV5Header[26] = 0x00;  // hor resol
                bitmapV5Header[27] = 0x00;  // hor resol

                bitmapV5Header[28] = 0x13;  // vert resol
                bitmapV5Header[29] = 0x0B;  // vert resol
                bitmapV5Header[30] = 0x00;  // vert resol
                bitmapV5Header[31] = 0x00;  // vert resol

                bitmapV5Header[32] = 0x00;  // colors in palette
                bitmapV5Header[33] = 0x00;  // colors in palette
                bitmapV5Header[34] = 0x00;  // colors in palette
                bitmapV5Header[35] = 0x00;  // compression

                bitmapV5Header[36] = 0x00;  // important colors
                bitmapV5Header[37] = 0x00;  // important colors
                bitmapV5Header[38] = 0x00;  // important colors
                bitmapV5Header[39] = 0x00;  // important colors

                fwrite(bitmapV5Header, 40, 1, filePointer);                 

                unsigned char paddingBytes[4];  // extra safety at 1 byte cost
                paddingBytes[0]=0x00;
                paddingBytes[1]=0x00;
                paddingBytes[2]=0x00;
                paddingBytes[3]=0x00;
                 
                for (int i=0; i<internal_height; i++)
                {
                    //std::cout << "fwrite -W " <<width<<"  H "<<height<<"   i: " << i << "  desp: " << (i*width*3) <<std::endl;
                    fwrite(internal_image+(i*internal_width*3),internal_width*3,1,filePointer);  //            fwrite(image, 3, 4, fp);    writing 3 bytes, 4 times 
                    fwrite(paddingBytes,padding,1,filePointer);
                    
                }
                fclose(filePointer);
                result =0;
            }
            else
            {
                result = -2;  // can't create, abort
            }
       }
       
       std::cout << " Image: " + p_name + " generated succesfully." << std::endl;
       return result;
    }

TinyImageJM::~TinyImageJM() /* release memory */
{
    if (internal_palette!=nullptr)
            {
                free(internal_palette);
            }
            
    if (internal_image!=nullptr)
            {
                free(internal_image);
            }
}

