/*
   COPYRIGHT (C) 2023 Anthony Yoho (amy125) All rights reserved.
   CS assignment
   Author.  Anthony Yoho
            amy125@uakron.edu
   Version. 1.01 04.20.2023
   Purpose: This program optimizes the binary tree
*/
#ifndef TREE_HPP
#define TREE_HPP
#include <iostream>
#include "Treenode.hpp"

// Tree class-template definition
template<typename NODETYPE> class Tree {
public:

    int Count()
    {
        return countNodes(rootPtr);
    }
    // insert node in Tree
    void insertNode(const NODETYPE& value) {
        insertNodeHelper(&rootPtr, value);
    }

    // begin preorder traversal of Tree
    void preOrderTraversal() const {
        preOrderHelper(rootPtr);
    }

    // begin inorder traversal of Tree
    void inOrderTraversal() const {
        inOrderHelper(rootPtr);
    }

    // begin postorder traversal of Tree
    void postOrderTraversal() const {
        postOrderHelper(rootPtr);
    }

    // get the depth of the tree
    int getDepth() const {
        return determineDepth(rootPtr);
    }

    // begin binary search
    TreeNode<NODETYPE>* binaryTreeSearch(NODETYPE val) const {
        return binarySearchHelper(rootPtr, val);
    }

    void Optimize()
    {
        int nodeCount = Count();
        NODETYPE* values = new NODETYPE[nodeCount];
        int index = 0;
        PopulateArrayInOrder(rootPtr, index, values);
        deleteSubTree(rootPtr);
        rootPtr = nullptr;
        InsertFromTheSortedArray(values, 0, nodeCount - 1);

    }

private:
    TreeNode<NODETYPE>* rootPtr{ nullptr };


    int countNodes(TreeNode<NODETYPE>* rootPtr) const
    {
        if (rootPtr == nullptr)
        {
            return 0;
        }

        return 1 + countNodes(rootPtr->leftPtr) + countNodes(rootPtr->rightPtr);
    }

    void PopulateArrayInOrder(TreeNode<NODETYPE>* subTreeRootPtr, int& index, NODETYPE arr[]) const
    {
        if (subTreeRootPtr != nullptr)
        {
            PopulateArrayInOrder(subTreeRootPtr->leftPtr, index, arr);
            arr[index] = subTreeRootPtr->getData();
            ++index;
            PopulateArrayInOrder(subTreeRootPtr->rightPtr, index, arr);
        }
    }

    void deleteSubTree(TreeNode<NODETYPE>* rootPtr)
    {
        if (rootPtr != nullptr)
        {
            deleteSubTree(rootPtr->getLeftPtr());
            deleteSubTree(rootPtr->getRightPtr());
            delete rootPtr;
            rootPtr = nullptr;
        }
    }

    void InsertFromTheSortedArray(NODETYPE arr[], int startIndex, int endIndex)
    {
        if (endIndex >= startIndex)
        {
            int middle = startIndex + (endIndex - startIndex) / 2;
            insertNode(arr[middle]);
            InsertFromTheSortedArray(arr, startIndex, middle - 1);
            InsertFromTheSortedArray(arr, middle + 1, endIndex);

        }
    }
    // utility function called by insertNode; receives a pointer
    // to a pointer so that the function can modify pointer's value
    void insertNodeHelper(
        TreeNode<NODETYPE>** ptr, const NODETYPE& value) {
        // subtree is empty; create new TreeNode containing value
        if (*ptr == nullptr) {
            *ptr = new TreeNode<NODETYPE>(value);
        }
        else { // subtree is not empty
            // data to insert is less than data in current node
            if (value <= (*ptr)->data) {
                insertNodeHelper(&((*ptr)->leftPtr), value);
            }
            else {
                insertNodeHelper(&((*ptr)->rightPtr), value);
            }
        }
    }

    // utility function to perform preorder traversal of Tree
    void preOrderHelper(TreeNode<NODETYPE>* ptr) const {
        if (ptr != nullptr) {
            std::cout << ptr->data << ' '; // process node
            preOrderHelper(ptr->leftPtr); // traverse left subtree
            preOrderHelper(ptr->rightPtr); // traverse right subtree
        }
    }

    // utility function to perform inorder traversal of Tree
    void inOrderHelper(TreeNode<NODETYPE>* ptr) const {
        if (ptr != nullptr) {
            inOrderHelper(ptr->leftPtr); // traverse to the left subtree
            std::cout << ptr->data << ' '; // process node
            inOrderHelper(ptr->rightPtr); // traverse to the right subtree
        }
    }

    // utility function to perform postorder traversal of Tree
    void postOrderHelper(TreeNode<NODETYPE>* ptr) const {
        if (ptr != nullptr) {
            postOrderHelper(ptr->leftPtr); // traverse left subtree
            postOrderHelper(ptr->rightPtr); // traverse right subtree
            std::cout << ptr->data << ' '; // process node
        }

    }

    // calculate the depth of the tree
    //rootPtr: the pointer to the root of the tree or sub tree when called recursively
    //         passed from calling statement
    //postcondition: the value returned is the height of the tree (i.e. max depth of the tree)
    //               -1: empty tree (i.e. rootPtr is null)
    //                0: only one node in a whole tree
    //            other: the height is always one less of the number of nodes of the deepest path.
    int determineDepth(TreeNode<NODETYPE>* rootPtr) const {

        if (rootPtr == nullptr) {
            return -1; // empty tree
        }
        else if (rootPtr->getLeftPtr() == nullptr && rootPtr->getRightPtr() == nullptr) {
            return 0; // only one node
        }
        else {
            int leftDepth = determineDepth(rootPtr->getLeftPtr());
            int rightDepth = determineDepth(rootPtr->getRightPtr());
            return 1 + std::max(leftDepth, rightDepth);
        }


    }

    // do a binary search on the Tree, searching the value val within a tree of rootPtr
    TreeNode<NODETYPE>* binarySearchHelper(TreeNode<NODETYPE>* rootPtr, NODETYPE val) const {

        TreeNode<NODETYPE>* nodePtr = rootPtr;

        while (nodePtr != nullptr)
        {
            std::cout << "Comparing " << val << " to " << nodePtr->data << ": ";
            if (nodePtr->data == val) {

                std::cout << "the search is complete" << std::endl;
                return nodePtr;
            }
            else if (val < nodePtr->data)
            {
                std::cout << "smaller, walk left" << std::endl;
                nodePtr = nodePtr->leftPtr;
            }
            else
            {
                std::cout << "larger, walk to the right" << std::endl;
                nodePtr = nodePtr->rightPtr;
            }

        }
    }

};

#endif // TREE_HPPif // TREE_HPP