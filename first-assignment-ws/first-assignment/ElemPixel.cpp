#include "ElemPixel.hpp"


//Constructor which initializes an element with a pixel and sets its next and previous to null
ElemPixel::ElemPixel(RGBPixelXY* ppixel)
{
    pixel=ppixel;
    next=nullptr;
    previous=nullptr;
}

//Constructor which initializes an element with the pixel and a pointer to the next element
ElemPixel::ElemPixel(RGBPixelXY* ppixel, ElemPixel* pnext)
{
    pixel=ppixel;
    next=pnext;
}

ElemPixel::~ElemPixel()
{
}

//Gets the pixel associated to this element
RGBPixelXY* ElemPixel::getPix()
{
    return pixel;  //Return pixel pointer
}

//Gets next element of this one
ElemPixel* ElemPixel::getNext()
{
    return next;    //Return next element pointer
}

//Gets previous element of this one
ElemPixel* ElemPixel::getPrevious()
{
    return previous;  //Return previous element pointer
}

//Set next element to this one
void ElemPixel::setNext(ElemPixel* pnext)
{
    next=pnext;    //Update next pointer
}

//Set previous element to this one
void ElemPixel::setPrevious(ElemPixel* pprevious)
{
    previous=pprevious;    //Update previous pointer
}