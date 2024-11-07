#include "Operation.hpp"

//Constructor which initializes the operation with a string and sets the next operation as null
Operation::Operation(std::string op)
{
	next = nullptr;
	operation = op;
}

//Constructor which initializes the operation with a string and sets the next operation as nextOp
Operation::Operation(std::string op, Operation* nextOp)
{
	next = nextOp;
	operation = op;
}

//Destructor
Operation::~Operation()
{
}

//Returns the operation string associated
std::string Operation::getOp()
{
	return operation;
}

//Gets next operation of this one
Operation* Operation::getNext()
{
    return next;
}
//Reverse image pixels RGB to get a negative image
void Operation::getNegative(QueuePixel* queuePix, TinyImageJM* myImg, std::string imageName, int numberOfUses)
{
    //Full copy of pixel queue to avoid modifying original data
    QueuePixel* queueCopy = queuePix->copyQueue();
    
    //Allocate memory for new image
    unsigned char* newImage;      
    newImage = (unsigned char *)malloc(sizeof(unsigned char) * myImg->getHeight() * myImg->getWidth() * 3);
    
    //Queue data structure used for the operation
    QueueDS* queue = new QueueDS();
    
    //Dequeue pixels from the copy of the original queue, enqueue into a temporary queue for the operation, and delete each dequeued element
    while(!queueCopy->isEmpty())
    {
        ElemPixel* elem = queueCopy->dequeue();
        RGBPixelXY *pp = elem->getPix();
        queue->enqueue(pp);
        
        delete(elem);
    }
    
    //Dequeue pixels from the operation queue and apply negative effect by substracting 255 to each RGB value and store them in newImage
    while(!queue->isEmpty())
    {   
        ElemPixel* elem = queue->dequeue();
        RGBPixelXY *pp = elem->getPix();
        pp->setComponents(255-pp->getR(),255-pp->getG(),255-pp->getB());
        pp->setIntoRaw(newImage,myImg->getWidth(),myImg->getHeight(),pp->getX(),pp->getY());
        
        delete(pp);  //Delete dequeued pp
        delete(elem);  //Delete dequeued elem
    }
    
    //Set modified data in myImg
    myImg->setNewImagePointerWithOldRemoval(newImage,myImg->getWidth(),myImg->getHeight());
    
    //Save image in disk, the filename changes based on the number of times this operations is used
    if(numberOfUses == 0)
    {
        myImg->saveImageToDisk(imageName+"_R.bmp");
    }
    else
    {
        myImg->saveImageToDisk(imageName +"_R"+ std::to_string(numberOfUses)+".bmp");
    }
    
    //Clean up dynamic memory
    delete(queue);
    delete(queueCopy);
}

//Applies a horizontal flip on the image 
void Operation::getFlipped(QueuePixel* queuePix, TinyImageJM* myImg, std::string imageName, int numberOfUses )
{
    //Full copy of pixel queue to avoid modifying original data
    QueuePixel* queueCopy = queuePix->copyQueue();
    
    //Allocate memory for new image
    unsigned char* newImage;      
    newImage = (unsigned char *)malloc(sizeof(unsigned char) * myImg->getHeight() * myImg->getWidth() * 3);
    
    //Stack data structure used for the operation
    StackDS* stack = new StackDS();
    
    //Dequeue pixels from the copy of the original queue, push into a temporary stack for the operation, and delete each dequeued element
    while(!queueCopy->isEmpty())
    {
        ElemPixel* elem = queueCopy->dequeue();
        RGBPixelXY *pp = elem->getPix();
        stack->push(pp);
        
        delete(elem);
        
    }
    
    //New copy of the original queue for swapping the "y" of the pixels using the stack (becouse the first copy)
    QueuePixel* tmpQueue = queuePix->copyQueue();
    
    //Pop pixels from the stack and dequeue pixels from tmpQueue, storing the pixels from the stack in newImage 
    //Swap the "y" coordinate of each stack pixel with the "y" coordinate of the corresponding pixel from tmpQueue
    while(!stack->isEmpty())
    {
        ElemPixel* elem = tmpQueue->dequeue();
        RGBPixelXY *pp = elem->getPix();
        RGBPixelXY *pp2 = stack->pop()->getPix();
        pp2->setIntoRaw(newImage,myImg->getWidth(),myImg->getHeight(),pp2->getX(),pp->getY());   //"y" swap
        
        delete(pp);   //Delete dequeued pixel
        delete(pp2);  //Delete popped pixel
        delete(elem); //Delete dequeued element
        
    }
    
    //Set modified data in myImg
    myImg->setNewImagePointerWithOldRemoval(newImage,myImg->getWidth(),myImg->getHeight());
    
    //Save image in disk, the filename changes based on the number of times this operations is used
    if(numberOfUses == 0)
    {
        myImg->saveImageToDisk(imageName+"_H.bmp");
    }
    else
    {
        myImg->saveImageToDisk(imageName +"_H"+ std::to_string(numberOfUses)+".bmp");
    }
    
    //Clean up dynamic memory
    delete(stack);
    delete(queueCopy);
    delete(tmpQueue);
}

//Applies a vertical flip on the image
void Operation::getFlopped(QueuePixel* queuePix, TinyImageJM* myImg, std::string imageName, int numberOfUses)
{
    //Full copy of pixel queue to avoid modifying original data
    QueuePixel* queueCopy = queuePix->copyQueue();
    
    //Allocate memory for new image
    unsigned char* newImage;      
    newImage = (unsigned char *)malloc(sizeof(unsigned char) * myImg->getHeight() * myImg->getWidth() * 3);
    
    //Doubly linked list data structure used for the operation
    DoublyLinkedList* dbllist = new DoublyLinkedList();
    
    //Dequeue pixels from the copy of the original queue, insert them one after another into the temporary doubly linked list (for reverse retrieval) for the operation
    while(!queueCopy->isEmpty())
    {
        ElemPixel* elem = queueCopy->dequeue();
        RGBPixelXY *pp = elem->getPix();
        dbllist->insertLast(pp);
        
        delete(elem);  //Delete dequeued element
    }
    
    //New copy of the original queue for swapping the "x" of the pixels using the doubly linked list (becouse the first copy is empty)
    QueuePixel* tmpQueue = queuePix->copyQueue();
    
    //Retrieve pixels from the doubly linked list from the last to the first pixel (reverse order) and dequeue pixels from tmpQueue
    //Storing the pixels from the doubly linked list in newImage.
    //Swap the "x" coordinate of each doubly linked list pixel with the "x" coordinate of the corresponding pixel from tmpQueue
    while(!dbllist->isEmpty())
    {
        ElemPixel* elem = tmpQueue->dequeue();
        RGBPixelXY *pp = elem->getPix();
        RGBPixelXY *pp2 = dbllist->retrieveLast()->getPix();
        pp2->setIntoRaw(newImage,myImg->getWidth(),myImg->getHeight(),pp->getX(),pp2->getY());  //"x" swap
        
        delete(pp);   //Delete dequeued pixel
        delete(pp2);  //Delete retrieved pixel
        delete(elem); //Delete dequeued element  
    }
    
    //Set modified data in myImg
    myImg->setNewImagePointerWithOldRemoval(newImage,myImg->getWidth(),myImg->getHeight());
    
    //Save image in disk, the filename changes based on the number of times this operations is used
    if(numberOfUses == 0)
    {
        myImg->saveImageToDisk(imageName+"_V.bmp");
    }
    else
    {
        myImg->saveImageToDisk(imageName +"_V"+ std::to_string(numberOfUses)+".bmp");
    }
    
    //Clean up dynamic memory
    delete(dbllist);
    delete(queueCopy);
    delete(tmpQueue);
}

//Darkens the image
void Operation::getDarken(QueuePixel* queuePix, TinyImageJM* myImg, std::string imageName, int numberOfUses)
{
    //Full copy of pixel queue to avoid modifying original data
    QueuePixel* queueCopy = queuePix->copyQueue();
    
    //Allocate memory for new image
    unsigned char* newImage;      
    newImage = (unsigned char *)malloc(sizeof(unsigned char) * myImg->getHeight() * myImg->getWidth() * 3);
    
    //Queue data structure used for the operation
    QueueDS* queue = new QueueDS();
    
    //Process each pixel in the copied queue until it is empty
    while(!queueCopy->isEmpty())
    {
        //Dequeue pixel from the copied queue
        ElemPixel* elem = queueCopy->dequeue();
        RGBPixelXY *pp = elem->getPix();
        
        //Calcualte average RGB value of the pixel
        int rgbmean = (pp->getR() + pp->getG() + pp->getB())/3;
        
        //Set the pixel to black if rgbmean is less than 128 otherwise the pixel is set to white
        if(rgbmean < 128)
        {
            pp->setComponents(0,0,0);  //Black
        }
        else
        {
            pp->setComponents(255,255,255);  //White
        }
        
        queue->enqueue(pp); //Enqueue the pixel
        
        delete(elem);  //Delete dequeued element
    }
    
    //New copy of the original queue to get original pixels
    QueuePixel* tmpQueue = queuePix->copyQueue();
    
    //Dequeue the processed pixels from queue and original pixels from tmpQueue
    //Mix original and processed pixels 
    //Store mixed pixels in newImage
    while(!queue->isEmpty())
    {   
        ElemPixel* elem = queue->dequeue();
        RGBPixelXY *pp = elem->getPix();
        RGBPixelXY *pp2 = tmpQueue->dequeue()->getPix();
        
        unsigned char meanR = (pp->getR() + pp2->getR()) / 2;  //Average red component
        unsigned char meanG = (pp->getG() + pp2->getG()) / 2;  //Average green component
        unsigned char meanB = (pp->getB() + pp2->getB()) / 2;  //Average blue component
        
        pp->setComponents(meanR, meanG, meanB);
        pp->setIntoRaw(newImage,myImg->getWidth(),myImg->getHeight(),pp->getX(),pp->getY());
        
        
        delete(pp);   //Delete pixel from queue
        delete(pp2);  //Delete pixel from tmpQueue
        delete(elem);  //Delete element from queue
    }
    
    //Set modified data in myImg
    myImg->setNewImagePointerWithOldRemoval(newImage,myImg->getWidth(),myImg->getHeight());
    
    //Save image in disk, the filename changes based on the number of times this operations is used
    if(numberOfUses == 0)
    {
        myImg->saveImageToDisk(imageName+"_O.bmp");
    }
    else
    {
        myImg->saveImageToDisk(imageName +"_O"+ std::to_string(numberOfUses)+".bmp");
    }
    
    //Clean up dynamic memory
    delete(queue);
    delete(queueCopy);
    delete(tmpQueue);
}

//Sort image pixels using the sum of RGB as primary criteria and the original order as secondary.
void Operation::getSorted(QueuePixel* queuePix, TinyImageJM* myImg, std::string imageName, int numberOfUses)
{
    //Full copy of pixel queue to avoid modifying original data
    QueuePixel* queueCopy = queuePix->copyQueue();
    
    //Allocate memory for new image
    unsigned char* newImage;      
    newImage = (unsigned char *)malloc(sizeof(unsigned char) * myImg->getHeight() * myImg->getWidth() * 3);
    
    //Sorted doubly linked list data structure used for the operation
    SortedDoublyLList* sdllist = new SortedDoublyLList();
    
    // Dequeue pixels from the copied queue and insert them into the sorted list
    while (!queueCopy->isEmpty())
    {
        ElemPixel* elem = queueCopy->dequeue();
        RGBPixelXY *pp = elem->getPix();
        
        sdllist->insertSorted(pp); 
        
        delete(elem);  //Delete dequeued element
    }
    
    //Initialize coordinates for placing pixels from top left to bottom right
    int x = 0;
    int y = myImg->getHeight() - 1;
    
    //Retrieve pixels from the sorted doubly linked list and place them into the new image
    while (!sdllist->isEmpty())
    {   
        ElemPixel* elem = sdllist->retrieveFirst();
        RGBPixelXY *pp = elem->getPix();
        
        pp->setIntoRaw(newImage, myImg->getWidth(), myImg->getHeight(), x, y);
        
        x++;
        if (x >= myImg->getWidth())  //If the end of the row is reached
        {
            x = 0;  //Reset x
            y--;  //Move to the next row
        }
        
        delete(pp);  //Delete dequeued pixel
        delete(elem); //Delete dequeued element
    }
    
    //Set modified data in myImg
    myImg->setNewImagePointerWithOldRemoval(newImage, myImg->getWidth(), myImg->getHeight());
    
    //Save image in disk, the filename changes based on the number of times this operations is used
    if(numberOfUses == 0)
    {
        myImg->saveImageToDisk(imageName+"_S.bmp");
    }
    else
    {
        myImg->saveImageToDisk(imageName +"_S"+ std::to_string(numberOfUses)+".bmp");
    }
    
    //Clean up dynamic memory
    delete(sdllist);
    delete(queueCopy);
}

