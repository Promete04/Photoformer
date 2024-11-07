#include "SortedDoublyLList.hpp"

//Constructor which initializes the sorted doubly linked list with its header and last set to null.
SortedDoublyLList::SortedDoublyLList()
{
    header = nullptr;  
    last = nullptr;
}

//Destructor which cleans up the memory used by the sorted doubly linked list
SortedDoublyLList::~SortedDoublyLList()
{
    //Loop until the list is empty
    while(!isEmpty())
    {
        delete(retrieveFirst());  //Retrieve and delete first element
    }
}

//Checks if the list is empty
bool SortedDoublyLList::isEmpty()
{
    return header == nullptr;  //If header is null then returns true (is empty)
} 

//Inserts a pixel into the list in order based on RGB component sum and the original order as second criteria
//We have decided to order the pixels from lowest RGB mean to highest 
void SortedDoublyLList::insertSorted(RGBPixelXY* ppix)
{
    ElemPixel* elem = new ElemPixel(ppix);  //Create new ElemPixel with the pixel given as a parameter 
    int rgbsumnew = elem->getPix()->getR() + elem->getPix()->getG() + elem->getPix()->getB();  //Calculate the sum of the RGB of the pixel
    bool inserted = false;  //Bool to check if element was inserted
    
    if (isEmpty())  //If list is empty the element is inserted and set to be the header and last of the list
    {
        header = elem;
        last = elem;
        elem->setNext(nullptr);   //Set element's next to null 
        elem->setPrevious(nullptr);   //Set element's previous to null
        inserted = true;   //Set inserted to true
    }
    else   //If the list is not empty
    {
        ElemPixel* tmp = header;  //Temporary pointer to the header, will be used to iterate through the list
        ElemPixel* prev = nullptr;  //Auxiliary pointer prev which will point to previous element, now set to null
        while (tmp != nullptr && !inserted)   //Iterate through the list to find the appropiate position of the element to be inserted
        {
            RGBPixelXY *tmpPix = tmp->getPix();  //Temporary pixel (pixel from the current tmp element)
            int rgbsumtmp = tmpPix->getR() + tmpPix->getG() + tmpPix->getB(); //Calculate the sum of the RGB of the current pixel
            
            //Check if the new element should be inserted before the current element 
            if (rgbsumnew < rgbsumtmp || (rgbsumnew == rgbsumtmp && (elem->getPix()->getX() < tmpPix->getX() || (elem->getPix()->getX() == tmpPix->getX() && elem->getPix()->getY() < tmpPix->getY())))) 
            {
                elem->setNext(tmp);  //Set element's next to be the current element
                elem->setPrevious(prev);   //Set element's previous to be prev

                if (prev != nullptr) //If previous is not null
                {
                    prev->setNext(elem);  //Update the previous element's next to point to the new element (the inserted one)
                }
                else  //If previous is null (the new element is the first element)
                {
                    header = elem;  //Set the header to the new element  
                }

                tmp->setPrevious(elem);  //Set current element's previous to new element
                inserted = true;   //Set inserted to true 
            }
            else
            {
                //Move to the next element of the list
                prev = tmp;  //Prev is now set to the current element
                tmp = tmp->getNext();  //Current element is updated to be its next
            }
            
        }
        
        //If it wasn't inserted, it will be inserted at the end of the list
        if(!inserted)
        {
            elem->setPrevious(last);  //Set new element's previous to last (it's the current last element)
            elem->setNext(nullptr);  //Set new element's next to null
            last->setNext(elem);   //Update the last element's next point to the new element
            last = elem;  //Update last to the new element
        }
    }
}

//Returns the first element in the list
ElemPixel* SortedDoublyLList::retrieveFirst()
{
    ElemPixel* tmp = nullptr;  //Temporary pointer set to null
    if (!isEmpty())   //Check if the list is empty
    {
        tmp = header;  //Stores current header in tmp
        header = header->getNext();  //Updates header to point to its next element

        if (header != nullptr)   //If the new header is not null
        {
            header->setPrevious(nullptr);    //Then the new header's previous is set to null
        }
        else  //If new header is null, it means that the list is now empty
        {
            last = nullptr;   //Last is set to null
        }
    }

    return tmp;  //Return tmp (retrieved element), it will be null if list is empty
}


