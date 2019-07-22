// Author: Mateusz Serafin
// Student number: 160272859	

// Polynomial class implementation

#include "stdafx.h"
#include <iostream>
#include "Quadratic.h"
#include <cmath>
#include "Polynomial.h"

using namespace std;

// constructors implementation
Polynomial::Polynomial(){}

Polynomial::Polynomial(int array_size)
{
	size = array_size; // setting size
	coefficients = new float[size]; // allocating array on the heap
}

Polynomial::Polynomial(float coef[], int array_size) : 
	size(array_size)	// setting size
{
	coefficients = new float[size];  // allocating array on the heap
	for (int i = 0; i < size; i++) 
		coefficients[i] = coef[i];	// copying array from stack to heap
}

Polynomial::Polynomial(const Polynomial &copy)    // copy constructor
{
	size = copy.size; // copying size
	coefficients = new float[size];	// declering array on the heap
	for (int i = 0; i < size; i++)
		coefficients[i] = copy.coefficients[i];	// copying array elements
}

// destructor implementation
Polynomial::~Polynomial()
{
	delete[] coefficients; // delete coefficients - was declared on the heap
}

// return the co-efficient of a given power of x.
float Polynomial::get_coefficient(int degree) const
{
	if (degree > size - 1 || degree < 0)	// check if degree is correct 
	{
		cout << "Entered co-efficient degree is too high or too low" << "\n";
		return 0;
	}
	return coefficients[degree]; 
}

// 	compute the value of the polynomial given a value for x
float Polynomial::compute_value(float x) const
{
	float value = 0; 
	for (int i = 0; i < size; i++)	// loop through elements 
		value += coefficients[i] * pow(x, i); // calculate value and sum up

	return value;
}

// operators overloading
Polynomial operator+(const Polynomial &lhs, const Polynomial &rhs)
{
	if (lhs.size > rhs.size) // check which polynomial is greater
	{
		Polynomial new_pol = lhs; // copy polynomial (using copy constructor)

		for (int i = 0; i < rhs.size; i++)	// sum with all elements from second polynomial  
			new_pol.coefficients[i] += rhs.coefficients[i];

		return new_pol;
	}
	else  // same as above
	{
		Polynomial new_pol = rhs;

		for (int i = 0; i < lhs.size; i++)	
			new_pol.coefficients[i] += lhs.coefficients[i];

		return new_pol;
	}
}

Polynomial operator-(const Polynomial &lhs, const Polynomial &rhs)
{
	if (lhs.size > rhs.size) // check which polynomial is greater
	{
		Polynomial new_pol = lhs; // copy polynomial (using copy constructor)

		for (int i = 0; i < rhs.size; i++)	//  elements with the same degree substraction  
			new_pol.coefficients[i] -= rhs.coefficients[i];

		return new_pol;
	}
	else 
	{
		Polynomial new_pol = rhs;

		for (int i = 0; i < lhs.size; i++)
			new_pol.coefficients[i] = lhs.coefficients[i] - rhs.coefficients[i];
		for (int i = lhs.size; i < rhs.size; i++)
			new_pol.coefficients[i] *= -1;	// invert all elements with degree higher than lhs degree

		return new_pol;
	}
} 

Polynomial operator*(const Polynomial &lhs, const Polynomial &rhs)
{
	int new_size = lhs.size + rhs.size - 1; // size for new polynomial, -1 because of first element in array - x^0 

	Polynomial new_pol(new_size);	// declaring new polynomial

	for (int i = 0; i < new_size; i++)
		new_pol.coefficients[i] = 0;	// temporary fill coefficients with 0 - will simplfy later calculations

	for (int i = 0; i < lhs.size; i++)	// multiply all elements from both polynomials
		for (int j = 0; j < rhs.size; j++)
			new_pol.coefficients[i + j] += lhs.coefficients[i] * rhs.coefficients[j];

	return new_pol;
}

bool operator==(const Polynomial &lhs, const Polynomial &rhs)
{
	if (lhs.size != rhs.size) // if size is different -> return false
		return false;
	
	for (int i = 0; i < lhs.size; i++) // loop and compare elements
		if (lhs.coefficients[i] != rhs.coefficients[i])	// if one of them is different -> return false
			return false;

	return true;  // size and corresponding elements are the same -> returns true
}

bool operator!=(const Polynomial &lhs, const Polynomial &rhs)
{
	if (lhs.size != rhs.size) // different size -> return true
		return true;
	
	for (int i = 0; i < lhs.size; i++)
		if (lhs.coefficients[i] != rhs.coefficients[i])	// if one of the elements is different -> return true
			return true;
	// anyother case return false;
	return false;
}

Polynomial & Polynomial::operator+=(const Polynomial & p)	
{
	*this = *this + p;  // use of overloaded + operator
	return *this;
}

Polynomial & Polynomial::operator-=(const Polynomial & p)	
{
	*this = *this - p;	// use of overloaded - operator
	return *this;
}

Polynomial & Polynomial::operator*=(const Polynomial & p)
{
	*this = *this * p;	// use of overloaded * operator
	return *this;
}

// overloaded assignment operator
Polynomial & Polynomial::operator=(const Polynomial & p)
{
	if (this == &p) return (*this);	// if both polynomials are the same

	delete[] coefficients;	// release the memory 

	// allocate new memory
	coefficients = new float[p.size];
	size = p.size;

	// copy values
	for (int i = 0; i < p.size; ++i)
		coefficients[i] = p.coefficients[i];
	
	return *this;
}

// input/output for polynomials
std::ostream & operator<<(std::ostream & output, const Polynomial & p)
{
	for(int i = p.size-1; i >=0; i--)		// coef = 0 -> don't display, ^0 dont show, coef < 0 then put - instead of +
	{
		//cout << "Size: " << p.size-1 << "\n";

		if (p.coefficients[i] > 0 && i != (p.size - 1))	// coef is positive number and it isn't polynomial highest degree 
			output << "+";
		
		//cout << "i: " << i << "\n";


		if (i > 1 && p.coefficients[i] != 0) // coef is not 0 and polynomial degree is higher than 1
			output << p.coefficients[i] << "x^" << i;
		else if(i==1 && p.coefficients[i] != 0)	// coef is not 0 and polynomial degree is 1
			output << p.coefficients[i] << "x";
		else if(p.coefficients[i] !=0)	// coef is not 0
			output << p.coefficients[i];
	}

	return output;
}

std::istream & operator>>(std::istream & input, Polynomial & p)
{
	cout << "Enter the degree of this polynomial: ";
	input >> p.size;
	cout << endl;
	p.size += 1; // there is one more number of elements than degree number of polynomial   

	if (p.coefficients)	// if coefficients array exist -> delete it
		delete[] p.coefficients;

	p.coefficients = new float[p.size];	// declare new array 

	for(int i = 0; i < p.size; i++)	// take coefficients from user
	{
		cout << "Enter the coefficient of x^" << i << ": ";
		input >> p.coefficients[i];
		cout << endl;
	}

	return input;
}

