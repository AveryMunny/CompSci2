
/*
   COPYRIGHT (C) 2017 Student Name (UANET ID ) All rights reserved.
   CS assignment
   Author.  Avery Munn
            acm183@uakron.edu
   Version. 1.01 09.09.2017
   Purpose: This program fib
*/
#include <iostream>

// prototypes
template <class T>
void printarray(const T[], int);
void chew_system_stack();
void swap(int& value1, int& value2);
int partition(int set[], int start, int end);
template <class T> 
void quicksort(T ar[], int start, int end);

/*
 * Recursive version of fibonacci
 */
int fibrecurse(int n)
{
    if (n <= 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return fibrecurse(n - 1) + fibrecurse(n - 2);
}

/*
 * Iterative (loop) version of fibonacci
 */
int fibiterate(int n) 
{
    int x = 0;
    int y = 1;
    if (n == 0)
        return x;
    if (n == 1)
        return y;
    int next = x+y;
    for (int i = 1; i < n; i++)
    {
        next = x + y;
        if (x > y)
            y = next;
        else
            x = next;
    }
    return next;
}

/*
 * Recursive quicksort
 */
template <class T>
void quicksort(T ar[], int start, int end) 
{
        int pivotPoint;
        if (start < end)
        {
            pivotPoint = partition(ar, start, end);
            //now the values with the index < pivotPoint are smaller than the value at pivotPoint
            //the values with the index > pivotPoint are greater than the value at the pivotPoint
            quicksort(ar, start, pivotPoint - 1);
            quicksort(ar, pivotPoint + 1, end);
        }
}

int main() {
    const int FIBLOOPS = 10;
    const int ARSIZ = 16;
    int ar[ARSIZ];

    std::cout << "Recursive fib: ";
    for (int i = 0; i < FIBLOOPS; ++i)
    {
        std::cout << fibrecurse(i) << " ";
    }
    std::cout << std::endl;
    std::cout << "Iterative fib: ";
    for (int i = 0; i < FIBLOOPS; ++i)
    {
        std::cout << fibiterate(i) << " ";
    }
    std::cout << std::endl;

    std::cout << "Quicksort:" << std::endl;
    // populate random array
    for (int i = 0; i < ARSIZ; ++i)
    {
        ar[i] = (i * 3037) % 2099;  // prime numbers! again!
    }
    printarray(ar, ARSIZ);
    quicksort(ar, 0, ARSIZ - 1);
    printarray(ar, ARSIZ);

    //std::cout << "Chewing system stack:" << std::endl;
    //chew_system_stack();

    return 0;
}

/*  utility functions, do not modify  */
template <class T>
void printarray(const T ar[], int s)
{
    for (int i = 0; i < s; ++i)
    {
        std::cout << ar[i] << " ";
    }
    std::cout << std::endl;
}

int partition(int set[], int start, int end)
{
    //this function is rearrange the array values so that values on the left
    //of pivotIndex are smaller and the values on the right of pivotIndex are greater
    //The function returns the pivotIndex
    int pivotValue, pivotIndex, mid;
    mid = (start + end) / 2;
    swap(set[start], set[mid]);
    pivotIndex = start;
    pivotValue = set[start];
    for (int scan = start + 1; scan <= end; scan++)
    {
        if (set[scan] < pivotValue)
        {
            pivotIndex++;
            swap(set[pivotIndex], set[scan]);
        }
    }
    swap(set[start], set[pivotIndex]);
    return pivotIndex;
}


void swap(int& value1, int& value2)
{
    int temp = value1;
    value1 = value2;
    value2 = temp;
}

/*
void printstackpointer()
{
    void* stack_pointer;
    // inline assembly language to get stack pointer
    __asm__ __volatile__("movl  %%esp,%%eax"
        :"=a"(stack_pointer)
    );
    std::cout << stack_pointer << std::endl;
}

void chew_system_stack()
{
    // Feel free to play with this, but please
    // do NOT enable this for your final commit!
    printstackpointer();
    chew_system_stack();
} */
/* end utilities */



