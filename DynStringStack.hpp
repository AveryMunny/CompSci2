
#ifndef DYNSTRINGSTACK_HPP
#define DYNSTRINGSTACK_HPP

#include <iostream>
using std::string;

class DynStringStack
{
private:
	struct StackNode
	{
		string value; //value in the node
		StackNode* next; //pointer in the next node
	};
	StackNode* top; //pointer to stack top

public:
	DynStringStack() { top = nullptr; } //constructor 
	~DynStringStack(); //deconstructor
	void push(string); //adding anothe object to the stack 
	string pop(); //removes an object
	bool isEmpty(); //checks to see if empty

};

#endif  //DYNSTRINGSTACK_H