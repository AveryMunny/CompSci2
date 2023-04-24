/*
   COPYRIGHT (C) 2016 Avery Munn (4796397) All rights reserved.
   CSII assignment 5 A
   Author.  Avery Munn
            acm183@uakron.edu
   Version. 1.01 09.09.2017

*/
// Implementation file for the charList class
#include "charList.hpp"
#include <iostream>

// Your coding required here 

//pre:builds object
//post: builds an object
//constructor
charList::charList()
{
    head = nullptr;
}

//pre:needs a node to insert
//post: inserts into the list
//inserting a node 
void charList::insertNode(double n)
{
    ListNode* newNode; //a new node
    ListNode* nodePtr; // traversing the list
    ListNode* previousNode = nullptr; //previous node

    //allocate a new node and store num there
    newNode = new ListNode;
    newNode->data = n;

    //if no nodes, make newNode the first
    if (!head)
    {
        head = newNode;
        newNode->next = nullptr;
    }
    else //otherise insert new node
    {
        //position nodePtr at the head of the list
        nodePtr = head;
        //initialize previousNode to nullptr
        previousNode = nullptr;

        //skip all nodes whose values is less than num
        while (nodePtr != nullptr && nodePtr->data >n)
        {
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }

        //if new node is to be the 1st inb the list, insert before all other nodes 
        if (previousNode == nullptr)
        {
            head = newNode;
            newNode->next = nodePtr;
        }
        else //otherwise insert after previous node
        {
            previousNode->next = newNode;
            newNode->next = nodePtr;
        }
    }

}

//pre:needs a node to delete
//post: deletes the node
//deleting a node
void charList::deleteNode(double n)
{
    ListNode* nodePtr; //traverse the list
    ListNode* previousNode = nullptr; //the previous node

    //if list is empty, do nothing
    if (!head)
        return;

    //determine if the first node is the one
    if (head->data == n)
    {
        nodePtr = head->next;
        delete head;
        head = nodePtr;
    }
    else
    {
        //initialize nodePtr to head of the list
        nodePtr = head;

        //skip all nodes whose data member is not equal to num
        while (nodePtr != nullptr && nodePtr->data != n)
        {
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }
        
        //if nodePtr is not at the end of the list, link the previous
        //node to the node after nodePtr, the delete nodePtr
        if (nodePtr)
        {
            previousNode->next = nodePtr->next;
            delete nodePtr;
        }
         
    }
}

//pre:needs a node to append
//post: appends the node into the back of the list
//appending a ndoe
void charList::appendNode(double n)
{
    ListNode* newNode; //points to a new node
    ListNode* nodePtr; //move through the list

    //allocate new node and store the number there
    newNode = new ListNode;
    newNode->data = n;
    newNode->next = nullptr;

    //if there aren't any nodes in the list, make a newNode the first node
    if (!head)
        head = newNode;
    else //otherwise, insert newNode at end
    {
        //initialize nodePtr to head of list
        nodePtr = head;

        //find the last node in the list
        while (nodePtr->next)
            nodePtr = nodePtr->next;
        //insert newNode as the last node
        nodePtr->next = newNode;
    }
}

//**************************************************
// displayList shows the value                     *
// stored in each node of the linked list          *
// pointed to by head.                             *
// pre: an empty parameter list                    *
// post: standard output of the linked list        *
//**************************************************

//pre:needs a node to display
//post:displaying the list
//displys list
void charList::displayList() const
{
    ListNode* nodePtr;  // To move through the list

    // Position nodePtr at the head of the list.
    nodePtr = head;
    short count = 0;

    // While nodePtr points to a node, traverse
    // the list.
    while (nodePtr)
    {
        // Display the value in this node.
        std::cout << "[" << nodePtr->data << "] -> ";
        ++count;
        // Move to the next node.
        nodePtr = nodePtr->next;
        if (count % 10 == 0) {
            std::cout << std::endl;
            count = 0;
        }
    }
    std::cout << std::endl;
}


// More of your coding required here 


//**************************************************
// Destructor                                      *
// This function deletes every node in the list.   *
// pre: n/a                                        *
// post: destroyed object                          *
//**************************************************

//pre:needs a node to deconstruct
//post: deconsturctor
//deleting the object 
charList::~charList()
{
    ListNode* nodePtr;   // To traverse the list
    ListNode* nextNode;  // To point to the next node

    // Position nodePtr at the head of the list.
    nodePtr = head;

    // While nodePtr is not at the end of the list...
    while (nodePtr != nullptr)
    {
        // Save a pointer to the next node.
        nextNode = nodePtr->next;

        // Delete the current node.
        delete nodePtr;

        // Position nodePtr at the next node.
        nodePtr = nextNode;
    }
}
