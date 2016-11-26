#include "stdafx.h"
#include "Multinomial.h"
#include <string>
#include <math.h>
#include <iomanip>
#include <stdio.h>
using namespace std;

Multinomial::Multinomial(int _n, double _dMN[])
{
	this->n = _n + 1; //переделываем степень многочлена в кол-во элементов в нем
	this->dMN = new double[n]; //динамически создаем массив
	if (!_dMN)//если указатель на массив не указывает на массив:)
			  //то соответственно заполнить его нулями, чтобы не было лишних неудобств
		for (int i = 0; i < n; i++)
			dMN[i] = 0;
	else
		//иначе заполнить его значениями переданного массива
		//причем заполняем задом наперед, для удобства работы с многочленами
		for (int i = 0; i < n; i++)
			dMN[i] = _dMN[i];
}

Multinomial::~Multinomial()
{
}

Multinomial::Multinomial()
{
}

Multinomial::Multinomial(int n)
{
}

void Multinomial::setMN(void)
{
}

void Multinomial::getMN(void)
{
}

Multinomial & Multinomial::operator=(const Multinomial & MN)
{

	// TODO: вставьте здесь оператор return
	return Multinomial();
}

Multinomial Multinomial::operator+(Multinomial & MN)
{
	int s, n1; //s - кол-во елементов в меньшем многочлене
			   //n1 - кол-во элементов в большем массиве
	double * dmn; //массив элементов
	if (this->n < MN.n) //если кол-во элементов текущего класса больше передаваемого, то
	{
		n1 = MN.n; //n1- кол-во элементов передаваемого объекта
		s = this->n - 1; //s - кол-во элементов текущего многочлена - 1
	}
	else //иначе наоборот
	{
		n1 = this->n;
		s = MN.n - 1;
	}
	dmn = new double[n1]; //создаем массив временных элементов
						  //складываем элементы первого мнгогочлена с элементами второго
	for (int i = 0; i < n1; i++)
	{
		if (i > s)
		{
			dmn = this->n > MN.n ? this->dMN : MN.dMN;
		}
		else
		{
			dmn[i] = this->dMN[i] + MN.dMN[i];
			//dmn = this->dMN + MN.dMN;
		}
	}
	return Multinomial(n1 - 1, dmn);//возвращаем новый объект
//	return Multinomial();
}

Multinomial Multinomial::operator-(Multinomial & MN)
{
	int s, n1; //s - кол-во елементов в меньшем многочлене
			   //n1 - кол-во элементов в большем массиве
	double * dmn; //массив элементов
	if (this->n < MN.n) //если кол-во элементов текущего класса больше передаваемого, то
	{
		n1 = MN.n; //n1- кол-во элементов передаваемого объекта
		s = this->n - 1; //s - кол-во элементов текущего многочлена - 1
	}
	else //иначе наоборот
	{
		n1 = this->n;
		s = MN.n - 1;
	}
	dmn = new double[n1]; //создаем массив временных элементов
						  //складываем элементы первого мнгогочлена с элементами второго
	for (int i = 0; i <= n1 + s; i++)
	{
		for (int g = 0; g <= i; g++)
		{
			dmn[i] = dmn[i] + this->dMN[g] * MN.dMN[i - g];
		}
		//	x = x + 1;
		//		printf("\n%d", R[i]);
	}

	return Multinomial(n1 - 1, dmn);//возвращаем новый объект

}

Multinomial Multinomial::operator*(Multinomial & MN)
{
	int n, m;
	double * dmn, *N, *M;
	n = this->n - 1;
	m = MN.n - 1;

	dmn = new double[m + n + 1]; // 3*3+1
	N = new double[m + n + 1]; // 3*3+1
	M = new double[m + n + 1]; // 3*3+1

	for (int i = 0; i < m + n + 1; i++)
	{
		dmn[i] = 0;
		N[i] = 0;
		M[i] = 0;
	}

	for (int i = 0; i < this->n; i++)
		N[i] = this->dMN[i];

	for (int i = 0; i < MN.n; i++)
		M[i] = MN.dMN[i];

	for (int i = 0; i <= n + m; i++)   //0 <=3+3 = 6
	{
		for (int g = 0; g <= i; g++)
		{
			dmn[i] = dmn[i] + N[g] * M[i - g];
		}
	}
	return Multinomial(n + m, dmn);
}

string Multinomial::getToString()
{
	string result;
	int j = n - 1;//степень

	for (int i = 0; i < n - 1; i++)
	{
		char strOut[20];//сюды будем записывать
		double tmp = dMN[i];//в этом числе компилятор сам убирает один ноль(у float 6 знаков после точки) и получается 23.234501
							//int b = 3;
							//формат  %f - для float %d - для целых
		if (tmp != 0)
		{
			sprintf_s(strOut, "%.2f", tmp);

			result += (const char*)strOut;
			result += "x^" + to_string(j) + "+";
		}
		j--;
	}
	char strOut[20];//сюды будем записывать
	double tmp = dMN[n - 1];//в этом числе компилятор сам убирает один ноль(у float 6 знаков после точки) и получается 23.234501

	sprintf_s(strOut, "%.2f", tmp);
	result += (const char*)strOut;
	//	}
	return result;
}

double Multinomial::value(double _x)
{
	return 0.0;
}


Multinomial Multinomial::operator /(Multinomial &ob)
{

	bool inAlgoritm = true;

	Multinomial temp;
	Multinomial ob_1;
	Multinomial ob_2;
	Multinomial ob_4;


	Multinomial MN;
	MN.n = ob.n - 1;
	MN.dMN = new double[ob.n + 1];
	for (int i = MN.n; i >= 0; i--)
	{
		MN.dMN[ob.n - i - 1] = ob.dMN[i];
	}


	temp.n = n - MN.n;
	temp.dMN = new double[temp.n + 1];
	memset(temp.dMN, 0, (temp.n + 1) * sizeof(double));

	ob_1.n = n;
	ob_1.dMN = new double[n + 1];
	for (int i = n; i >= 0; i--)
		ob_1.dMN[i] = dMN[i];

	ob_2.n = MN.n;
	ob_2.dMN = new double[MN.n + 1];
	for (int i = MN.n; i >= 0; i--)
		ob_2.dMN[i] = MN.dMN[i];

	ob_4.n = ob_1.n;
	ob_4.dMN = new double[ob_1.n + 1];

	double mnojnik;
	int k = 0;
	int i, j;
	while (inAlgoritm)
	{

		for (int i = MN.n; i >= 0; i--)
			ob_4.dMN[i] = MN.dMN[i];

		if (ob_2.n < ob_1.n)
		{
			for (i = ob_1.n, j = ob_2.n; i >= 0; i--, j--)
				if (j < 0)
					ob_4.dMN[i] = 0;
				else
					ob_4.dMN[i] = ob_2.dMN[j];
		}



		mnojnik = ob_1.dMN[ob_1.n] / ob_4.dMN[ob_1.n];

		temp.dMN[temp.n - k] = mnojnik;
		k++;



		for (int i = 0; i <= ob_1.n; i++)
			ob_4.dMN[i] *= mnojnik;

		for (int i = 0; i <= ob_1.n; i++)
			ob_1.dMN[i] -= ob_4.dMN[i];

		ob_1.n--;
		if (ob_2.n > ob_1.n) inAlgoritm = false;

	}

	Multinomial tmp;
	tmp.n = temp.n + 1;
	tmp.dMN = new double[temp.n + 1];
	for (int i = 0, j = temp.n; i <= tmp.n; i++, j--)
		tmp.dMN[i] = temp.dMN[j];



	return tmp;

}


