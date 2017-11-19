#include <iostream>
#include "fraction.h"

using namespace std;

fraction::fraction(int n, int d)
	: numerator(n), denominator(d)
{
	int common = gcd(numerator, denominator);
	numerator /= common;
	denominator /= common;
}


fraction fraction::add(fraction f)
{
	int num = (numerator * f.denominator) + (denominator * f.numerator);
	int den = (denominator * f.denominator);

	return fraction(num, den);
}


fraction fraction::sub(fraction f)
{
	int num = (numerator * f.denominator) - (denominator * f.numerator);
	int den = (denominator * f.denominator);

	return fraction(num, den);
}


fraction fraction::mult(fraction f)
{
	int num = (numerator * f.numerator);
	int den = (denominator * f.denominator);

	return fraction(num, den);
}


fraction fraction::div(fraction f)
{
	int num = (numerator * f.denominator);
	int den = (denominator * f.numerator);

	return fraction(num, den);
}


void fraction::print()
{
	cout << endl << numerator << "/" << denominator << endl;
}


 void fraction::read()
{
	 cout << "Please enter a numerator: " << endl;
	 cin >> numerator;
	 
	 cout << "Please enter a denominator: " << endl;
	 cin >> denominator;
}


// Euclid's Algorithm for finding the greatest common divisor
int gcd(int u, int v)
{
	u = (u < 0) ? -u : u;  // make u non-negative
	v = (v < 0) ? -v : v;  // make v non-negative

	while (u > 0)
	{
		if (u < v)
		{
			int t = u;	// swap u and v
			u = v;
			v = t;
		}

		u -= v;
	}

	return v;  // the GCD of u and v
}