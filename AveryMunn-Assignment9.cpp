/*
   COPYRIGHT (C) 2017 Student Name (UANET ID ) All rights reserved.
   CSII assignment 9
   Author.  Student Name
            zippy@zips.uakron.edu
   Version. 1.01 09.09.2017
   Purpose: This program is the test cases for the assignment
*/
#include <iostream>
#include <iomanip>

//using 
using namespace std;

// prototypes
void unpackCharacters(char[], unsigned);
void displayBits(unsigned);

//global variables
 const size_t MASK1 = 255;
 const size_t MASK2 = 65280;
 const size_t MASK3 = 16711680;
 const size_t MASK4 = 4278190080;
 int MASKS[] = { MASK1, MASK2, MASK3, MASK4 };


int main() {
    char characters[4];
    unsigned packed{ 1633903975 }; // a, c, e, g

    cout << "The packed character representation is:\n";
    displayBits(packed);

    // demonstrate unpacking of characters
    unpackCharacters(characters, packed);
    cout << "\nThe unpacked characters are: ";
    for (size_t i{ 0 }; i < 4; ++i) {
        cout << characters[i] << " ";
    }
    cout << endl;

    cout << "\nThe unpacked characters in bits are:" << endl;
    for (size_t i{ 0 }; i < 4; ++i) {
        displayBits(characters[i]);
    }
}

// take apart the characters
void unpackCharacters(char characters[], unsigned pack)
{
   displayBits(MASK1);
   displayBits(MASK1& pack);
   displayBits(MASK2 & pack);
   displayBits((MASK3 & pack));
   displayBits(MASK4 & pack);
   for (size_t i = 0; i < 4; i++)
   {
       characters[i] = (MASKS[i] & pack)>>8*i;

   }
}

// display the bits of value
void displayBits(unsigned value)
{
    //printing an unsigned integer in bits
    const int SHIFTER = 8 * sizeof(unsigned) - 1;
    const unsigned MASK = 1 << SHIFTER;

    std::cout << std::setw(10) << value << " = ";

    //display bits
    for (size_t i = 1; i <= SHIFTER + 1; i++)
    {
        std::cout << (value & MASK ? '1' : '0');
        value <<= 1; //shifting left 1

        if (i % 8 == 0)
            std::cout << ' ';
    }
    std::cout << std::endl;
}

