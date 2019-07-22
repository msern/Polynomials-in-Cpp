// Author: Mateusz Serafin
// Student number: 160272859	

// Test class

#include "stdafx.h"
#include <iostream>
#include "Quadratic.h"
#include <cmath>
#include "Polynomial.h"

using namespace std;

void quadratic_test()
{
	Quadratic q1(-1, 4, 3);
	Quadratic q2(2, -5, 1);

	cout << "----------  Quadratic implementation tests: ----------  \n" << endl;

	cout << "1) Returning the co-efficient of a given power of x: " << endl;
	cout << "  Co-efficient of x^2 in q1 is " << q1.get_coefficient(2) << "     (should be 3)" << endl;
	cout << "  Co-efficient of x^0 in q2 is " << q2.get_coefficient(0) << "     (should be 2)" << endl;

	cout << "2) Computing the value of the quadratic given a value for x: " << endl;
	cout << "  Value of q1 for x=3 is " << q1.compute_value(3) << "     (3*3^2 + 4*3 - 1 = 38)" << endl;
	cout << "  Value of q2 for x=-2 is " << q2.compute_value(-2) << "   (1*(-2)^2 - 5*(-2) + 2 = 16)" << endl;

	cout << "3) Addition and substraction operators test: " << endl;
	Quadratic q3 = q1 + q2;
	Quadratic q4 = q2 - q1;
	cout << "  " << q1 << " + (" << q2 << ") = " << q3 << endl;
	cout << "  " << q2 << " - (" << q1 << ") = " << q4 << endl;

	cout << "4) Implementation of == != += and -= operators test: " << endl;
	cout << "  " << q1 << " += " << q2 << " = ";
	q1 += q2;
	cout << q1 << endl;
	cout << "  " << q2 << " -= " << q1 << " = ";
	q2 -= q1;
	cout << q2 << endl;

	bool b1 = q1 == q2;
	bool b2 = q1 != q2;
	cout << "  Is q1 == q2? " << b1 << "  (0 for false)" << endl;
	cout << "  Is q1 != q2? " << b2 << "  (1 for true)" << endl;
	Quadratic q5(1, -1 , 4);	// same as q1
	bool b3 = q1 == q5;
	bool b4 = q1 != q5;
	cout << "  Is q1 == q5? " << b3 << "  (1 for true)" << endl;
	cout << "  Is q1 != q5? " << b4 << "  (0 for false)" << endl;

	cout << "5) Input and output test: " << endl;
	Quadratic q6;
	cin >> q6;
	cout << q6 << endl;

	cout << "--------------------- Test end --------------------- \n" << endl;
}

void polynomial_test()
{

	float arr1[4] = { -1, 4, 3, 1 };
	float arr2[3] = { 2, -5, 1 };

	Polynomial p1(arr1, 4);
	Polynomial p2(arr2, 3);

	cout << "----------  Polynomial implementation tests: ----------  \n" << endl;

	cout << "1) Returning the co-efficient of a given power of x: " << endl;
	cout << "  Co-efficient of x^2 in p1 is " << p1.get_coefficient(2) << "     (should be 3)" << endl;
	cout << "  Co-efficient of x^2 in p2 is " << p2.get_coefficient(2) << "     (should be 1)" << endl;

	cout << "2) Computing the value of the polynomial given a value for x: " << endl;
	cout << "  Value of p1 for x=3 is " << p1.compute_value(3) << "     (1*3^3 + 3*3^2 + 4*3 - 1 = 65)" << endl;
	cout << "  Value of p2 for x=-2 is " << p2.compute_value(-2) << "   (1*(-2)^2 - 5*(-2) + 2 = 16)" << endl;

	cout << "3) Addition and substraction operators test: " << endl;
	Polynomial p3 = p1 + p2;
	Polynomial p4 = p2 - p1;
	cout << "  " << p1 << " + (" << p2 << ") = " << p3 << endl;
	cout << "  " << p2 << " - (" << p1 << ") = " << p4 << endl;

	cout << "4) Implementation of == != += and -= operators test: " << endl;
	cout << "  " << p1 << " += " << p2 << " = ";
	p1 += p2;
	cout << p1 << endl;
	cout << "  " << p2 << " -= " << p1 << " = ";
	p2 -= p1;
	cout << p2 << endl;

	bool b1 = p1 == p2;
	bool b2 = p1 != p2;
	cout << "  Is p1 == p2? " << b1 << "  (0 for false)" << endl;
	cout << "  Is p1 != p2? " << b2 << "  (1 for true)" << endl;
	Polynomial p5 = p1;	// copy constructor
	bool b3 = p1 == p5;
	bool b4 = p1 != p5;
	cout << "  Is p1 == p5? " << b3 << "  (1 for true)" << endl;
	cout << "  Is p1 != p5? " << b4 << "  (0 for false)" << endl;

	cout << "5) Input and output test: " << endl;
	Polynomial p6;
	cin >> p6;
	cout << p6 << endl << endl;

	cout << "6) * and *= operators for polynomial multiplication test: " << endl;

	Polynomial p7 = p1 * p2;
	cout << "  " << p1 << " * (" << p2 << ") = " << p7 << endl;
	cout << "  " << p7 << " *= " << p2 << " = ";
	p7 *= p2;
	cout << p7 << endl;

	cout << "\n--------------------- Test end --------------------- \n" << endl;
}

int main()
{					
	quadratic_test();
	polynomial_test();

	system("pause");	// stop console

	return 0;
}