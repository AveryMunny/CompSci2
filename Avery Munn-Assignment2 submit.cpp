/*
Avery Munn
Assignemnt 2
acm183@uakron.edu
purpose: Letting people know their taxes
*/

//includes
#include "Tax.hpp"
#include <iostream>

//Prototype of taxTake and taxPrint are in Tax.hpp, so it must be included

//using
using std::cout;
using std::cin;

int main()
{
	struct taxPayer numOne;
	struct taxPayer numTwo;

	//calling functions for input and output
	taxTaker(&numOne, &numTwo); //input

	//outputting
	taxPrint(&numOne, &numTwo); //output

	return 0;
}
