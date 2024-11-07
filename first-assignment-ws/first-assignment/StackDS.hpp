#ifndef STACKDS_HPP
#define STACKDS_HPP

#include "ElemPixel.hpp"

class StackDS
{
    ElemPixel* top;  //Pointer to the of the stack
public:
    StackDS();    //Constructor
    ~StackDS();   //Destructor

    void push(RGBPixelXY* ppix);   //Introduces an element to the top of the stack
    bool isEmpty();    //Checks if stack is empty
    ElemPixel* pop();  //Returns the top element of the stack
};

#endif // STACKDS_HPP
