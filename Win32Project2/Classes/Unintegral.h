#pragma once
#include "Integral.h"
#include "Multinomial.h"

class Unintegral : public Integral
{

public:
	 Multinomial getIntegral(/*Multinomial MN*/)
	 {
		 Multinomial result;
		 result.n = n ;
		 result.dMN = new double[result.n];
		 for (int i=0; i<n;i++)
		 {
			 result.dMN[i] = dMN[i] / (result.n-1 - i);
		 }
		 result.dMN[n - 1] = 0;
	//	 int p = MN.n;
		 return result;
	 }
	 
	Unintegral(int n, double _dMN[]) :Integral(n, _dMN) {};
	~Unintegral();

};
