#ifndef OPERATION_HPP
#define OPERATION_HPP

#include "QueuePixel.hpp"
#include "QueueDS.hpp"
#include "StackDS.hpp"
#include "DoublyLinkedList.hpp"
#include "SortedDoublyLList.hpp"
#include <string>
#include "peque-image-manager/TinyImageJM.hpp"
#include "peque-image-manager/RGBPixelXY.hpp"

class Operation
{
	Operation* next;       //Pointer to next operation
	std::string operation;    //The operation (R,S,H...)
	
public:
	Operation(std::string operation);  //Constructor with the operation string as parameter
    Operation(std::string operation, Operation* nextOp);  //Constructor with the operation string and the operation's next as parameters
	~Operation();  //Destructor
    
    Operation* getNext();    //Gets next operation of this one
    void getNegative(QueuePixel* queuePix, TinyImageJM* myImg, std::string imageName, int numberOfUses);  //Reverse image pixels RGB to get a negative image
    void getFlipped(QueuePixel* queuePix, TinyImageJM* myImg, std::string imageName, int numberOfUses);   //Applies a horizontal flip on the image 
    void getDarken(QueuePixel* queuePix, TinyImageJM* myImg, std::string imageName, int numberOfUses);    //Darkens the image
    void getFlopped(QueuePixel* queuePix, TinyImageJM* myImg, std::string imageName, int numberOfUses);   //Applies a vertical flip on the image
    void getSorted(QueuePixel* queuePix, TinyImageJM* myImg, std::string imageName, int numberOfUses);    //Sort image pixels using the sum of RGB as primary criteria and the original order as secondary.
	std::string getOp();  //Returns the operation string associated

};

#endif // OPERATION_HPP
