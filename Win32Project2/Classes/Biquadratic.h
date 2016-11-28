#pragma once
#include "stdafx.h"
#include "Equation.h"

class Biquadratic : public Equation
{
public:
	Biquadratic(int n, double _dMN[]) : Equation(n, _dMN) {};
	~Biquadratic();
	double findRoot() {return 0};
};