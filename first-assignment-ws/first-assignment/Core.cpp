#include "Core.hpp"

Core::Core()
{
        //Initializes Core object.
}

Core::~Core()
{
}

void Core::boot()
{
    //Loading phase
    std::cout << R"(
                      ..........                       
                     ..#-.....#..                      
        #######.......#..####..#.. .....#######        
        ###  ...#######..####..+####..##.. ####        
        ###..#..##.-#.#.######.#.###....#..####        
         ......#...#.#.#+.+######.#...#...#..          
        ..##...+....#.#-....####.#.#..#...##+.         
        ...#.#+####.#.#-##.#.##..#.###+####...         
        ...#.#######.+#######..#...######.#....        
      ..####.########.#.+....-++.########.####..       
    ..##..##..##..#####...###..###.##.###+#...##...    
    .##...#.##.#...##.#.########.#..###.##..-.-##-.    
    .##...#.##.#.###.-#.#..#.#..#.###...#.#.-..#.-.    
    .##.-.#.#..##+##..#.#....##.#.#####...#.#.##-..    
    .##+..#.#..#..#####...-#.#.######..#..#.-.###..    
    ...####+###....+..-.#---.#.#.##.#...########...    
      ..#.#.#.####...###.......##...####.#.-##..       
         ...-.##....##+-#######++#..#+##.#..           
           .#.##..#+.#.....#......###.##.#.            
           ..+#.####.##.-#+#-...##.+.#.#.#.            
            ..#...+.#.##..-++###.#.#.#.#...            
        ###   ..#-#.#.#.#-....-##.#####..  ####        
        ###     ..#.#...##+...-.+##.#..    ####        
        #######   .##...###+.##.#.#..   #######        
                    ..###########..                    
                      ..........                       )" << std::endl;
    std::cout << "\n Welcome to Photoformer, introduce the name of the image to edit (.bmp format): "  << std::endl;
    std::string imageName;
    std::string imageNameSimplified;
    
    //We have decided that the user must input the image file name with the .bmp extension
    std::cout<<" ";
    std::cin >> imageName;
    
    //Extract the simplified name from the image (without the .bmp extension)
    imageNameSimplified = imageName.substr(0, imageName.find_last_of('.'));
    
    TinyImageJM* myImg= new TinyImageJM(imageName);
    myImg->loadImageFromDisk();
    
    // Queue to store image pixels
    QueuePixel* queuePix = new QueuePixel();  
    
    if (myImg->isValid())  //If the image is valid (is .bmp)
    {
        std::cout << " Inserted image is valid. \n"<<std::endl;
        
        // Load image pixels into the queue created
        for (int y=0; y<myImg->getHeight(); y++)
        {
            for (int x=0; x<myImg->getWidth(); x++)
            {
                RGBPixelXY *pp = new RGBPixelXY(x,y);
            
                // Pick the pixel from the image and store it in the queue
                pp->getFromRaw(myImg->getImagePointertoInternal(),myImg->getWidth(),myImg->getHeight(),x,y);
                queuePix->enqueue(pp);         
            }
        }
     }
     
    else
        
        {
           std::cout << " Introduced image is not valid ---- "<< myImg->getInternalError() <<std::endl;
        }
        
    
    //Request user operations
    
    if(myImg->isValid()) //If the image is valid (is .bmp)
    {
        std::cout << " Now chose the operation (or operations) you want to perform on your image. Available operations:" << std::endl;
        
        std::cout << "\n    R -> Reverse image pixels to get a negative image. \n    S -> Sorting image pixels using the sum of all three components (RGB) and the original order as second criteria. \n    H -> Flipped image. \n    V -> Flopped image. \n    O -> Darken.  \n\n Press X to jump to the processing phase. \n"<< std::endl;
        
        std::string op;
        
        bool exit = false;
        
        OpStack* opstack = new OpStack();
        
        // Gets the operations introduced by the user until the user inserts "X"
        while(!exit)
        {
            std::cout<<" ";
            std::cin >> op ;
            
            
            if(op == "X" || op == "x")
            {
                std::cout << "\n Generating images. \n" << std::endl;
                exit = true;
            }
            else if(op != "R" && op != "r" && op != "S" && op != "s" && op != "H" && op != "h" && op != "V" && op != "v" && op != "O" && op != "o" && op != "X" && op != "x" )
            {
                std::cout << " Invalid input. Introduce a proper operation. \n" << std::endl;
            }
            else
            {
                opstack->push(op);   //Valid operations are stored in an operation stack.
                std::cout<<"\n Operation stored, introduce the next operation or type X to finish the process. \n"<<std::endl;
            }
            
        }
        
        //-------------------------------------------------------------------------------------------------------------------------------------------
        //Data processing phase
        
        //Initialize operation counters
        //We have decided that the user can request the same operation several times generating different image files
        int r = 0, s = 0, h = 0, v = 0, o = 0;
        
        //Process each operation and update the counter if necessary
        while(!opstack->isEmpty())
        {
            Operation* op = opstack->pop();
            
            if(op->getOp() == "R" || op->getOp() == "r")
            {
                op->getNegative(queuePix, myImg, imageNameSimplified, r);
                r++;
            }
            else if(op->getOp() == "S" || op->getOp() == "s")
            {
                op->getSorted(queuePix, myImg, imageNameSimplified, s);
                s++;
            }
            else if(op->getOp() == "H" || op->getOp() == "h")
            {
                op->getFlipped(queuePix,myImg, imageNameSimplified, h);
                h++;
            }
            else if(op->getOp() == "V" || op->getOp() == "v")
            {
                op->getFlopped(queuePix,myImg, imageNameSimplified, v);
                v++;
            }
            else if(op->getOp() == "O" || op->getOp() == "o")
            {
                op->getDarken(queuePix,myImg, imageNameSimplified, o);
                o++;
            } 
            else
            {
                std::cout << " No more operations were introduced." << std::endl;  //Operation stack is empty
            }
            
            delete(op);  //Cleans up the operation
        }
        
        // Cleanup
        delete(queuePix);
        delete(opstack);
        
        std::cout << "\n Finished processing, check output folder. You may close the program now. " << std::endl;
    }
    
    
    std::cin.ignore();     //Ignores pressing "enter" for closing the program until the end.
    std::cin.get();        //Closes program if press "enter".
}
