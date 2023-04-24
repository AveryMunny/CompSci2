#include "RectangleDataType.hpp"
#include <math.h>

//pre:needs input from user giving the coordinates of the rectangle
//post: should have 4 sides by the end of it
//sets the sides of the rectangle
Rectangle::Rectangle(Point one, Point two, Point three, Point four) //constructor
{
	if (testing(one, two, three, four))
	{
		side1 = one.getB() - four.getB();
		side2 = two.getA() - one.getA();
		side3 = two.getB() - three.getB();
		side4 = three.getA() - four.getA();
		length = fabs(side1);
		width = fabs(side4);
		area = length * width;
		perimeter = side1 + side2 + side3 + side4;
	}
	else Rectangle();
}

//pre:needs a length
//post: returns a length
//fucntion should return the length
double Rectangle::getLength()
{
	return length;
}

//pre:needs a width
//post: returns a width
//fucntion should return the width
double Rectangle::getWidth()
{
	return width;
}

//pre: needs 4 sides
//post: will return the perimeter
//gives the perimeter
double Rectangle::getPerimeter()
{
	return perimeter;
}

//pre:needs width and length
//post: returns the area
//gives the area of the rectangle
double Rectangle::getArea()
{
	return area;
}

//pre:needs points 
//post: returns whether or not this is a square
//tests to see if it's a square
bool Rectangle::isSquare()
{
	if (pow(side1, 2.0) == area)
		return true;
	else
		return false;
}

bool Rectangle::testing(Point one, Point two, Point three, Point four)
{
	if (one.getA() != four.getA() || one.getB() != two.getB() || two.getA() != three.getA() || three.getB() != four.getB())
		return false;
	else if (one.getA() < 0 || one.getA() > 20 || one.getB() < 0 || one.getB() > 20 || two.getA() < 0 || two.getA() > 20 || two.getB() < 0 || two.getB() > 20 || three.getA() < 0 || three.getA() > 20 || three.getB() < 0 || three.getB() > 20 || four.getA() < 0 || four.getA() > 20 || four.getB() < 0 || four.getB() > 20)
		return false;
	else
		return true;

}

//pre: nothing
//post: sets values = to nothing
//creats a rectangle object
Rectangle::Rectangle()
{
	width = 0;
	length = 0;
	perimeter = 0;
	area = 0;
}

