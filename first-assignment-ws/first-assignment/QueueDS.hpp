#ifndef QUEUEDS_HPP
#define QUEUEDS_HPP

#include "ElemPixel.hpp"

class QueueDS
{
    ElemPixel* front;  //Pointer to the front element in the queue
    ElemPixel* rear;   //Pointer to the rear element on the queue
    
public:
    QueueDS();   //Constructor
    ~QueueDS();  //Destructor
    
    void enqueue(RGBPixelXY* ppix);   //Adds new element to the rear of the queue
    bool isEmpty();     //Checks if queue is empty
    ElemPixel* dequeue();   //Returns front element of the queue

};

#endif // QUEUEDS_HPP
