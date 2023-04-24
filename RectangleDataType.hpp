#ifndef RECTANGLEDATATYPE_HPP
#define RECTANGLEDATATYPE_HPP

struct Point
{
	double a;
	double b;
	double getA()
	{
		return a;
	}
	double getB()
	{
		return b;
	}
};
class Rectangle
{
private:
	double length;
	double width;
	double area;
	double perimeter;
	bool square;
	double side1, side2, side3, side4;

public:
	double getLength(); //returns the length of the rectangle 
	double getWidth(); //returns the width of the rectangle
	double getPerimeter(); //calculates the perimeter
	double getArea(); //calculates the area
	bool isSquare(); //tests to see if the shape is a square
	bool testing(Point one, Point two, Point three, Point four); //testing values 
	Rectangle(Point one, Point two, Point three, Point four); //constructor
	Rectangle();

};

#endif //RECTANGLEDATATYPE_HPP
