#pragma once
#include "Multinomial.h" 

class Integral : public Multinomial
{
public:

	Multinomial differentiate(Multinomial & MN);
	virtual Multinomial getIntegral(/*Multinomial MN*/) = 0;
	Integral();
	Integral(int n, double _dMN[]) :Multinomial(n, _dMN) {};
	~Integral();
};