#pragma once
#include "Multinomial.h"

 class Equation: Multinomial
 {

 public:

	 double p;

	 double countInPoint();
	 bool testInRoot();
	 virtual double findRoot()= 0;

	 Equation();
	 ~Equation();
 };
