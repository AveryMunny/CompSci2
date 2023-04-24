// Avery munn
// Assignment 1A
// Avery Munn-Assignment 1A
//

#include <iostream>
#include <memory>
#include <string>
#include <cctype>

//prototypes
std::unique_ptr<char[]> deleteRepeats(char original[]);

//Global variables
const int SIZE = 10;

int main()
{
	//defining variables 
	char originalArray[SIZE];
	std::unique_ptr<char[]> noRepeats;

	//setting the values of the original array
	originalArray[0] = 'a';
	originalArray[1] = 'b';
	originalArray[2] = 'b';
	originalArray[3] = 'c';
	originalArray[4] = 'a';
	originalArray[5] = 'c';
	originalArray[6] = 'a';
	originalArray[7] = 'c';
	originalArray[8] = 'b';
	originalArray[9] = 'c';

	//calling functions
	noRepeats = deleteRepeats(originalArray);
	for (int i = 0; i < 3; i++)
	{
		{
			std::cout << noRepeats[i] << ", ";
		}
	}
}

//functions
std::unique_ptr<char[]> deleteRepeats(char original[SIZE])
{
	//declaring variables
	int count = 0;
	std::unique_ptr<char[]> newArray(new char [SIZE]);
	
	for (int i = 0; i < SIZE; i++)
	{
		bool exists = false;
		for (int j = 0; j < i; j++)
		{
			if (original[j] == original[i])
			{
				exists = true;
				break;
			
			}
		}
		
		if (exists == false)
		{
			newArray[count] = original[i];
			count++;
		}
	}
	return newArray;
}


