#ifndef COMPLEX_HPP
#define COMPLEX_HPP
#include <string>


class Complex
{
	friend std::ostream &operator << (std::ostream& output, const Complex& a);
	friend std::istream &operator >> (std::istream& input, Complex& a);
public:
   Complex(double = 0.0, double = 0.0); // default constructor
   Complex operator+(const Complex& rhs) const; //function add
   Complex operator-(const Complex& rhs) const; // function subtract
   Complex operator*(const Complex& rhs) const; // function multiply
   std::string toString() const;  // return string representation
   void setComplexNumber(double, double); // set complex number
   Complex& operator=(const Complex& rhs);
   bool operator==(const Complex& rhs) const;
   bool operator!=(const Complex& rhs) const;

private:
   double realPart;
   double imaginaryPart;
};

#endif

