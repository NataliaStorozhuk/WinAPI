#pragma once
#include "stdafx.h"
#include "Integral.h"

class Defintegral : public Integral
{

public:
	double min, max, step;

	virtual double getIntegral(double min, double max, double step);
};
