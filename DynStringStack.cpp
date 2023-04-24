#include "DynStringStack.hpp"
#include <iostream>


using namespace std;

//pre: needs an object
//post: clears object
// deconstructor
DynStringStack::~DynStringStack()
{
	StackNode* nodeptr = nullptr, * nextNode = nullptr;

	//position nodePtr at top of stack
	nodeptr = top;

	//traverse and delete each node
	while (nodeptr != nullptr)
	{
		nextNode = nodeptr->next;
		delete nodeptr;
		nodeptr = nextNode;
	}
}

//pre: needs an object
//post: adds another object
// adds another piece to the stack
void DynStringStack::push(string n)
{
	StackNode* newNode = nullptr; //point to a new node

	//allocate new node and store there
	newNode = new StackNode;
	newNode->value = n;

	//if no nodes then make newNode the first
	if (isEmpty())
	{
		top = newNode;
		newNode->next = nullptr;
	}
	else
	{
		newNode->next = top;
		top = newNode;
	}
}

//pre: needs an object
//post: clears object from stack (top one)
// removes top object from stack
string DynStringStack::pop()
{
	StackNode* temp = nullptr; //temporary pointer
	string other;

	if (isEmpty())
	{
		cout << "Stack is empty \n";
	}
	else
	{
		other = top->value;
		temp = top->next;
		delete top;
		top = temp;
	}
	return other;
}

//pre: needs a stack to check 
//post: returns true if emtpy, flase if not
// checks to see if stack is empty
bool DynStringStack::isEmpty()
{
	if (!top)
		return true;
	else
		return false;
}
