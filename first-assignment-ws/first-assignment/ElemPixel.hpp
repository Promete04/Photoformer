#ifndef ELEMPIXEL_HPP
#define ELEMPIXEL_HPP

#include "peque-image-manager/RGBPixelXY.hpp"

class ElemPixel
{
    RGBPixelXY* pixel;      //Pointer to RGBPixelXY object
    ElemPixel* next;        //Pointer to next element
    ElemPixel* previous;    //Pointer to previous element
    
public:
    ElemPixel(RGBPixelXY* ppixel);    //Constructor with a pixel as parameter
    ElemPixel(RGBPixelXY* ppixel, ElemPixel* pnext);   //Constructor with a pixel and next element as parameters
    ~ElemPixel();   //Destructor

    RGBPixelXY* getPix();   //Gets the pixel associated to this element
    
    ElemPixel* getNext();     //Gets next element of this one
    ElemPixel* getPrevious();   //Gets previous element of this one
    void setNext(ElemPixel* pnext);   //Set next element to this one
    void setPrevious(ElemPixel* pprevious);     //Set previous element to this one
};

#endif // ELEMPIXEL_HPP