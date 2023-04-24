#include <iostream>
#include <stdexcept>
#include <math.h>
#include "RectangleDataType.hpp" // include definition of class Rectangle
#include "Rectangle.cpp"

/*

Create a sophisticated Rectangle class. This class stores only the Cartesian coordinates of the four corners of the
rectangle. The constructor calls a set function that accepts four sets of coordinates and verifies that
each of these is in the first quadrant with no single x- or y-coordinate larger than 20.0. The set function
also verifies that the supplied coordinates do, in fact, specify a rectangle.

Provide member functions that calculate the length, width, perimeter and area. The length is the larger of the two
dimensions.

Include a predicate function square that determines whether the rectangle is a square.
*/

int main() {
    Point w{ 1.0, 1.0 };
    Point x{ 5.0, 1.0 };
    Point y{ 5.0, 3.0 };
    Point z{ 1.0, 3.0 };
    Point j{ 0.0, 0.0 };
    Point k{ 1.0, 0.0 };
    Point m{ 1.0, 1.0 };
    Point n{ 0.0, 1.0 };

    Rectangle r1{z, y, x, w };
    std::cout << "Rectangle 1:\n";
    std::cout << "length = " << r1.getLength();
    std::cout << "\nwidth = " << r1.getWidth();
    r1.getPerimeter();
    r1.getArea();
    std::cout << "\nThe rectangle "
        << (r1.isSquare() ? "is" : "is not")
        << " a square.\n";

    Rectangle r2{ j, k, m, n };
    std::cout << "\nRectangle 2:\n";
    std::cout << "length = " << r2.getLength();
    std::cout << "\nwidth = " << r2.getWidth();
    r2.getPerimeter();
    r2.getArea();
    std::cout << "\nThe rectangle "
        << (r2.isSquare() ? "is" : "is not")
        << " a square.\n";

}
