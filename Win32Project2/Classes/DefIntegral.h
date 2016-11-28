#pragma once
#include "stdafx.h"
#include "Integral.h"
#include <math.h>

class Defintegral : public Integral
{

public:
	double min, max;

	Multinomial Defintegral::getIntegral(double max, double min)
	{
		double imax = max, imin = min;
		//первообр
		Multinomial result;
		result.n = n;
		result.dMN = new double[result.n];
		for (int i = 0; i < n - 1; i++)
		{
			result.dMN[i] = dMN[i] / (result.n - 1 - i);
		}
		result.dMN[n - 1] = 0;

		//значение
		double a = 0, b = 0;
		for (int i = 0; i < n; i++)
		{
			a += result.dMN[i] * (pow(imax, n - 1 - i));
			b += result.dMN[i] * (pow(imin, n - 1 - i));
		}

		result.n = a - b;
		return result;
	}

	Defintegral(int n, double _dMN[]) :Integral(n, _dMN) {};
};