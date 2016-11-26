#pragma once
#include <string>
using namespace std;

class Multinomial {

	

public:
	int n;
	double *dMN;
	///		int arg, n, i, power, p, array[], km;
	Multinomial(int _n, double _dMN[]);

	~Multinomial();
	Multinomial();

	Multinomial(int n);

	void setMN(void);

	void getMN(void);

	Multinomial & operator=(const Multinomial & MN);

	Multinomial operator+(Multinomial & MN);

	Multinomial operator-(Multinomial & MN);

	Multinomial operator*(Multinomial & MN);
	Multinomial operator/(Multinomial & MN);

	Multinomial back(Multinomial & MN);

	//Multinomial back();

	string getToString();

	double value(double _x);
	
};