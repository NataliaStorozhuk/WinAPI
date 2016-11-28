#include "stdafx.h"
#include "Integral.h"

Multinomial Integral::differentiate()
{
	Multinomial result;
	result.n = n - 1;
	result.dMN = new double[result.n];
	for (int i = 0; i < result.n; i++)
	{
		result.dMN[i] = dMN[i] * (result.n - i);
	}
	return result;

	return Multinomial();
}


Integral::Integral()
{
}

Integral::~Integral()
{
}
