#pragma once
#include "stdafx.h"
#include "Equation.h"

class Quadratic : public Equation
{
public:

	Quadratic(int n, double _dMN[]) : Equation(n, _dMN) {};
	~Quadratic();
	double findRoot() { return 0; };

};
