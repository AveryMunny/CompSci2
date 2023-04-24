#include "Complex.hpp"
#include <iostream>
#include <stdio.h>

//pre:needs an object to create
//Post: builds the object
//default constructor
Complex::Complex(double x, double y)
{
	realPart = x;
	imaginaryPart = y;
}

//pre:needs a complex object
//post: adds the objects together
// adding function
Complex Complex::operator+(const Complex& rhs) const
{
	Complex temp;
	temp = realPart + rhs.realPart;
	temp = imaginaryPart + rhs.imaginaryPart;
	return temp;
}

//pre: needs two complex objects
//post: returns new subtracted object
// subtracts the two objects
Complex Complex::operator-(const Complex& rhs) const
{
	Complex temp;
	temp = realPart - rhs.realPart;
	temp = imaginaryPart - rhs.imaginaryPart;
	return temp;
}

//pre: needs a complex object
//post: returns the new object 
// multiplies the two objects together
Complex Complex::operator*(const Complex& rhs) const
{
	Complex temp;
	temp = realPart * rhs.realPart;
	temp = imaginaryPart * rhs.imaginaryPart;
	return temp;
}

//pre: needs a complex object
//post: returns a readable string
// makes it readable
std::string Complex::toString() const
{
	return std::to_string(realPart) + " " + std::to_string(imaginaryPart) + "i";
}

//pre: needs two doubles
//post: sets real and imaginary parts equal to values passed
// basically a constuctor
void Complex::setComplexNumber(double x, double y)
{
	Complex(x,y);
}

//pre: needs information being released
//post: returns said information
// overriding the << operator
 std::ostream &operator<< (std::ostream& output, const Complex& a)
{
	output << a.toString();
		return output;
}

//pre: needs information to be stored 
//post: returns new information
// overriding the >> operator
std::istream &operator>> (std::istream& input, Complex& a)
{
	input >> a.realPart >> a.imaginaryPart;
	return input;
}

//pre: needs a complex object
//post: reutrns new variables
//overriding = operator
Complex& Complex::operator=(const Complex& rhs) 
{
	realPart = rhs.realPart;
	imaginaryPart = rhs.imaginaryPart;
	return *this;
}

//pre: needs a complex object
//post: reutrns true if same, false if not
//overriding == operator
bool Complex::operator==(const Complex& rhs) const
{
	if (realPart == rhs.realPart && imaginaryPart == rhs.imaginaryPart)
		return true;
	else
		return false;
}

//pre: needs a complex object
//post: reutrns true if not same, false if are
//overriding != operator
bool Complex::operator!=(const Complex& rhs) const
{
	if (realPart != rhs.realPart && imaginaryPart != rhs.imaginaryPart)
		return true;
	else
		return false;
}



