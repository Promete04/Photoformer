#include "DoublyLinkedList.hpp"

//Constructor which initializes an empty doubly linked list
DoublyLinkedList::DoublyLinkedList()
{
    header = nullptr;  //Set header to nullptr
    last = nullptr;    //Set last to nullptr
}

//Destructor which cleans up the memory used by the list
DoublyLinkedList::~DoublyLinkedList()
{
    //Loop until the list is empty
    while(!isEmpty())
    {
        delete(retrieveLast());  //Retrieve and delete the last element
    }
}

//Insert a new element at the end of the list
void DoublyLinkedList::insertLast(RGBPixelXY* ppix)
{
    ElemPixel* elem = new ElemPixel(ppix);  //Create new ElemPix with the pixel given as parameter
    
    if(isEmpty())  //Check if list is empty
    {
        header = elem;   //Set header to new element
        last = elem;     //Set last to new element
        elem->setNext(nullptr);    //Set element next to null
        elem->setPrevious(nullptr);   //Set element previous to null
        
    }
    else   //If the is list not empty
    {
        elem->setNext(nullptr);   //Set element next to null (will be the last)
        elem->setPrevious(last);  //Set element previous to the current last
        last->setNext(elem);      //Set the current last next to be the new element
        last = elem;              //Update last to be the new element
    }
    
}

//Retrieve the last element from the list
ElemPixel* DoublyLinkedList::retrieveLast()
{
    ElemPixel* tmp = nullptr;  //Temporary pointer to null
    
    if(!isEmpty())     //Checks if list is empty
    {
        tmp = last;    //Store last element in tmp
        last = last->getPrevious();   //Move last pointer to the previous element
        
        if(last != nullptr)     //If there is previous element
        {
            last->setNext(nullptr);    //Set last next to null
            
        }
        else   //If list is empty
        {
            header = nullptr;  //Header set to null
        }
    }
    
    return tmp;    // Return tmp element (the one to retrieve)
}

//Checks if list is empty
bool DoublyLinkedList::isEmpty()
{
    return header == nullptr;   //If header is null then returns true (is empty)
}



