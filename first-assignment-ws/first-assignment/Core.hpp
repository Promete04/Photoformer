#ifndef CORE_HPP
#define CORE_HPP

#include <iostream>

#include "peque-image-manager/TinyImageJM.hpp"

#include "peque-image-manager/RGBPixelXY.hpp"

#include "QueuePixel.hpp"

#include "OpStack.hpp"

class Core
{
public:
    Core();       //Constructor
    ~Core();      //Destructor
    
    void boot();   //Method to start the main application.

};

#endif // CORE_HPP
