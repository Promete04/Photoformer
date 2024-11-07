#ifndef SORTEDDOUBLYLLIST_HPP
#define SORTEDDOUBLYLLIST_HPP

#include "ElemPixel.hpp"

class SortedDoublyLList
{
    ElemPixel* header;  //Pointer to the first element of the sorted doubly linked list
    ElemPixel* last;    //Pointer to the last element of the sourted doubly linked list
public:
    SortedDoublyLList();   //Constructor
    ~SortedDoublyLList();  //Destructor
    
    bool isEmpty();    //Checks if the list is empty
    void insertSorted(RGBPixelXY* ppix);  //Inserts a pixel into the list in order based on RGB component sum and the original order as second criteria
    ElemPixel* retrieveFirst();  //Returns the first element in the list

};

#endif // SORTEDDOUBLYLLIST_HPP
