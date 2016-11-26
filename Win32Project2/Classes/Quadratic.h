#pragma once
#include "Equation.h"

class Quadratic : public Equation 
{
public:

	Quadratic();
	~Quadratic();
	virtual double findRoot();

};
