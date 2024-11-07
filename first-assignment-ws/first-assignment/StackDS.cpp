#include "StackDS.hpp"

//Constructor which initializes the stack with its top pointing to null
StackDS::StackDS()
{
    top=nullptr;  
}

//Destructor which cleans up the memory used by the stack
StackDS::~StackDS()
{
    //Loop until stack is empty
    while(!isEmpty())
    {
        delete(pop());  //Pop and delete the top element
    }
}

//Check if stack is empty
bool StackDS::isEmpty()
{
    return top == nullptr;  //If top is null then return true (is empty)
}

//Returns the top element of the stack
ElemPixel* StackDS::pop()
{
    ElemPixel* tmp = nullptr;  //Temporary pointer set to null
    
    if(!isEmpty())  //Check if list is empty
    {
        tmp = top;  //Store top element in tmp
        top = top->getNext();  //Update top to point to its next element
    }
    
    return tmp; //Return tmp (contains the element to pop, if stack is empty returns null)
}

//Introduces an element to the top of the stack
void StackDS::push(RGBPixelXY* ppix)
{
    ElemPixel* elem = new ElemPixel(ppix, top);  //Create a new element with its next pointing to the current top
    top = elem;  //Update top to the new element
    
}





