#ifndef QUEUEPIXEL_HPP
#define QUEUEPIXEL_HPP

#include "ElemPixel.hpp"


class QueuePixel
{
    ElemPixel* front;  //Pointer to the front element in the queue
    ElemPixel* rear;   //Pointer to the rear element on the queue
    
public:
	QueuePixel();   //Constructor
	~QueuePixel();   //Destructor

    void enqueue(RGBPixelXY* ppix); //Adds new element to the rear of the queue
    bool isEmpty();   //Checks if queue is empty
    ElemPixel* dequeue();   //Returns front element of the queue
    QueuePixel* copyQueue();  //Returns a copy of the queue
	
	
};

#endif // QUEUEPIXEL_HPP
