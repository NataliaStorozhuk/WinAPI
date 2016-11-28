#pragma once
#include "stdafx.h"
#include "Integral.h"
#include "Multinomial.h"

class Unintegral : public Integral
{

public:
	Multinomial getIntegral(double min, double max)
	{
		Multinomial result;
		result.n = n;
		result.dMN = new double[result.n];
		for (int i = 0; i < n; i++)
		{
			result.dMN[i] = dMN[i] / (result.n - 1 - i);
		}
		result.dMN[n - 1] = 0;

		return result;
	}

	Unintegral(int n, double _dMN[]) :Integral(n, _dMN) {};
	~Unintegral() {};

};
