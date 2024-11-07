#ifndef DOUBLYLINKEDLIST_HPP
#define DOUBLYLINKEDLIST_HPP

#include "ElemPixel.hpp"

class DoublyLinkedList
{
    ElemPixel* header;    //Pointer to first element of the list.
    ElemPixel* last;      //Pointer to last element of the list.
    
public:
    DoublyLinkedList();   //Constructor
    ~DoublyLinkedList();  //Destructor
    
    void insertLast(RGBPixelXY* ppix);     //Inserts a new element at the end of the doubly linked list.
    ElemPixel* retrieveLast();             //Retrieves the last element of the doubly linked list.
    bool isEmpty();                        //Check if the list is empty

};

#endif // DOUBLYLINKEDLIST_HPP
