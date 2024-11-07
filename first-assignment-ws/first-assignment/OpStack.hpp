#ifndef OPSTACK_HPP
#define OPSTACK_HPP

#include "Operation.hpp"

class OpStack
{
	Operation* top;  //Pointer to the top of the operation stack
	
public:
	OpStack();      //Constructor
	~OpStack();     //Destructor

	Operation* pop();   //Returns the top of the operation stack
	void push(std::string operation);   //Introduces an operation to the top of the operation stack
	bool isEmpty();    //Checks if stack is empty
};

#endif // OPSTACK_HPP
