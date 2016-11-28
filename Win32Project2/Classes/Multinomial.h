#pragma once
#include "stdafx.h"
#include <string>
using namespace std;

class Multinomial {

public:
	int n;

	double *dMN;

	Multinomial(int _n, double _dMN[]);

	~Multinomial();

	Multinomial();

	Multinomial(int n);

	void setMN(void);

	void getMN(void);

	Multinomial & operator=(const Multinomial & MN);

	Multinomial operator+(Multinomial & MN);

	Multinomial operator-(Multinomial & MN);

	Multinomial operator*(Multinomial & MN);

	Multinomial operator/(Multinomial & MN);

	string getToString();

	double value(double _x);

};