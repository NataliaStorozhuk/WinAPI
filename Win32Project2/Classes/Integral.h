#pragma once
#include "Multinomial.h" 

class Integral : public Multinomial
{
	public: 

	Multinomial differentiate(Multinomial & MN);
	virtual double getIntegral(Multinomial & MN)=0;
	Integral();
	~Integral();
};