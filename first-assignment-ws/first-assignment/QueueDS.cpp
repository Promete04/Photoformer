#include "QueueDS.hpp"

//Constructor which initializes the queue with its front and rear set to null
QueueDS::QueueDS()
{
    front=nullptr;
    rear=nullptr;

}

//Destructor which cleans up the memory used by the queue
QueueDS::~QueueDS()
{
    //Loop until queue is empty
    while(!isEmpty())  
    {
        delete(dequeue());  //Dequeues and deletes front element
        
    }
}

//Checks if queue is empty
bool QueueDS::isEmpty()
{
    return front == nullptr;  //If front is null then returns true (is empty)
}

//Returns front element of the queue
ElemPixel* QueueDS::dequeue()
{
    ElemPixel* tmp;  //Temporaty pointer 
    
    if(!isEmpty())  //Check if queue is empty
    {
        tmp = front;  //Stores front element in tmp
        front = front->getNext();  //Update front to point to its next element
        
        if(front == nullptr)  //If front is null (queue is empty)
        {
            rear = nullptr;  //Rear is set to null
        }
    }
    else
    {
        tmp = nullptr; //If queue is empty, tmp is set to null
    }
    
    return tmp; //Return tmp (dequeued element)
}


//Adds new element to the rear of the queue
void QueueDS::enqueue(RGBPixelXY* ppix)
{
    ElemPixel* p_elem = new ElemPixel(ppix);  //Create new ElemPix with the pixel given as a parameter
    
    if(isEmpty())  //Check if queue is empty, if it is, new element is set to be the front and rear of the queue
    {
        front = p_elem;  
        rear = p_elem;   
    }
    else  //If it's not empty
    {
        rear->setNext(p_elem);  //The current rear's next is set to be the new element
        rear = p_elem;  //Rear is updated to be the new element    
    } 
}

