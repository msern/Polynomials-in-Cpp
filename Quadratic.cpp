// Author: Mateusz Serafin
// Student number: 160272859	

// Quadratic class implementation


#include "stdafx.h"
#include <iostream>
#include "Quadratic.h"
#include <cmath>

using namespace std;

// constructors implementation
Quadratic::Quadratic(){}

Quadratic::Quadratic(float coef0, float coef1, float coef2)
{
	this->coef0 = coef0;
	this->coef1 = coef1;
	this->coef2 = coef2;
}

// destructor
Quadratic::~Quadratic(){}

// return the co-efficient of a given power of x
float Quadratic::get_coefficient(int degree) const
{
	switch (degree)
	{
	case 0:
		return coef0;
	case 1:
		return coef1;
	case 2:
		return coef2;
	default:
		return 0;
	}
}

// compute the value of the quadratic given a value for x 
float Quadratic::compute_value(float x) const
{
	return (coef2 * x * x) + (coef1 * x) + coef0;
}

// overloading operators
Quadratic operator+(const Quadratic& rhs, const Quadratic& lhs)
{
	Quadratic quadratic;	// new object

	quadratic.coef0 = rhs.coef0 + lhs.coef0;
	quadratic.coef1 = rhs.coef1 + lhs.coef1;
	quadratic.coef2 = rhs.coef2 + lhs.coef2;

	return quadratic;
}

Quadratic operator-(const Quadratic& rhs, const Quadratic& lhs)
{
	Quadratic quadratic;	// new object

	quadratic.coef0 = rhs.coef0 - lhs.coef0;
	quadratic.coef1 = rhs.coef1 - lhs.coef1;
	quadratic.coef2 = rhs.coef2 - lhs.coef2;

	return quadratic;
}

bool operator==(const Quadratic& rhs, const Quadratic& lhs)
{
	if (rhs.coef0 == lhs.coef0 && rhs.coef1 == lhs.coef1 && rhs.coef2 == lhs.coef2)	// all coefficients are the same
		return true;
	else
		return false;
}

bool operator!=(const Quadratic& rhs, const Quadratic& lhs)
{
	if (rhs.coef0 != lhs.coef0 || rhs.coef1 != lhs.coef1 || rhs.coef2 != lhs.coef2) // one of coefficients is different
		return true;
	else
		return false;
}

Quadratic& Quadratic::operator+=(const Quadratic &q)
{
	*this = *this + q;	// solution based on + operator overloading
	return *this;
}

Quadratic& Quadratic::operator-=(const Quadratic &q)
{
	*this = *this - q; // solution based on - operator overloading
	return *this;
}

// overloading input/output 
std::ostream& operator<<(std::ostream& output, const Quadratic &q)
{
	output << q.coef2 << "x^2";
	if (q.coef1 > 0)
		output << "+" << q.coef1 << "x";
	else if(q.coef1 == 0){}	// do nothing
	else
		output << q.coef1 << "x";
	if (q.coef0 > 0)
		output << "+" << q.coef0;
	else if (q.coef0 == 0) {}	// do nothing
	else
		output << q.coef0;

	return output;
}

std::istream& operator>>(std::istream &input, Quadratic &q)
{
	cout << "Enter the coefficient of x^2: ";
	input >> q.coef2;
	cout << "Enter the coefficient of x: ";
	input >> q.coef1;
	cout << "Enter a constant (x^0): ";
	input >> q.coef0;
	
	return input;
}

