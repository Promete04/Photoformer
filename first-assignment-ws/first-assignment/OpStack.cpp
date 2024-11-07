#include "OpStack.hpp"

//Constructor which initializes the stack with its top pointing to null
OpStack::OpStack()
{
	top=nullptr;
}

//Destructor which cleans up the memory used by the stack
OpStack::~OpStack()
{
    //Loop until the stack is empty
	while(!isEmpty())
    {
        delete(pop()); //Pop and delete top element
    }
}

//Return top operation from the stack
Operation* OpStack::pop()
{   
    Operation* tmp = nullptr;   //Temporary pointer to null
    
    if(!isEmpty()) //Check if stack is empty
    {
        tmp = top;   //Store top operation in tmp
        top = top->getNext();   //Update top to point to the next operation
        
    }    
	return tmp;  //Return tmp (contains the operation to pop, if stack is empty returns null)
}

//Check if stack is empty
bool OpStack::isEmpty()
{
	return top == nullptr;  //If top is null then return true (is empty)
}

//Introduces a new operation to the top of the operation stack
void OpStack::push(std::string op)
{
	Operation* operation = new Operation(op, top); //Create new operation with its next pointing to the actual top
	top = operation;  //Update top to be the new operation
}

