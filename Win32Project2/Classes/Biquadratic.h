#pragma once
#include "Equation.h"

class Biquadratic : public Equation
{
public: 
	Biquadratic();
	~Biquadratic();
	virtual double findRoot();
};