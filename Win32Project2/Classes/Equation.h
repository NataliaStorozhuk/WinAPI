#pragma once
#include "stdafx.h"
#include "Multinomial.h"

class Equation : Multinomial
{

public:

	double p;

	double countInPoint();
	bool testInRoot();
	virtual double findRoot() = 0;

	Equation(int n, double _dMN[]) :Multinomial(n, _dMN) {};
	~Equation();
};
