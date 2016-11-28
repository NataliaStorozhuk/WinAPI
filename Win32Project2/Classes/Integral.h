#pragma once
#include "stdafx.h"
#include "Multinomial.h" 

class Integral : public Multinomial
{
public:

	Multinomial differentiate();
	virtual Multinomial getIntegral(double min, double max) = 0;
	Integral();
	Integral(int n, double _dMN[]) :Multinomial(n, _dMN) {};
	~Integral();
};