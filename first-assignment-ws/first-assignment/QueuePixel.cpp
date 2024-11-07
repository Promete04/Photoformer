#include "QueuePixel.hpp"

//Constructor which initializes the queue with its front and rear set to null
QueuePixel::QueuePixel()
{
    front=nullptr;
    rear=nullptr;
}

//Destructor which cleans up the memory used by the queue
QueuePixel::~QueuePixel()
{
    //Loop until queue is empty
    while(!isEmpty())
    {
        delete(dequeue());  //Dequeues and deletes front element
        
    }
}

//Checks if the queue is empty 
bool QueuePixel::isEmpty()
{
    return front == nullptr;  //If front is null, then returns true (is empty)
}

//Returns the front element of the queue
ElemPixel* QueuePixel::dequeue()
{
    ElemPixel* tmp;  //Temporary pointer
    
    if(!isEmpty())   //Check if queue is empty
    {
        tmp = front;   //Store front element in tmp
        front = front->getNext();  //Update front to point to its next element
        
        if(front == nullptr)   //If front is null (queue is empty)
        {
            rear = nullptr;    //Rear is set to null
        }
    }
    else
    {
        tmp = nullptr;  //If queue is empty, tmp is set to null
    }
    
    return tmp;  //Return tmp (dequeued element)
    
}

//Adds a new element to the rear of the queue
void QueuePixel::enqueue(RGBPixelXY* ppix)
{
    ElemPixel* elem = new ElemPixel(ppix);  //Create new ElemPixel with the pixel given as a parameter 
    
    if(isEmpty())  //Check if queue is empty, if it is, new element is set to be the front and rear of the queue
    {
        front = elem;
        rear = elem;
    }
    else  //If it's not empty
    {
        rear->setNext(elem);   //The current rear's next is set to be the new element
        rear = elem;   //Rear is updated to be the new element    
    }
    
}

//Creates a copy of the queue
QueuePixel* QueuePixel::copyQueue()
{
    QueuePixel* newQueue = new QueuePixel();  //Creates new queue
    
    ElemPixel* tmp = front;  //Temporary pointer to front
    
    while(tmp != nullptr)  //Iterate through the original queue starting from its front
    {
        RGBPixelXY* original = tmp->getPix();  //Get pixel from tmp
        RGBPixelXY* copy = new RGBPixelXY(original->getX(), original->getY(), original->getR(), original->getG(), original->getB());  //Creates new pixel (a copy)
        newQueue->enqueue(copy);  //Enqueue the copied pixel into the new queue 
        tmp = tmp->getNext();  //Update tmp to point to its next element
    }
    
    return newQueue;  //Returns copied queue
}

