#include "MyRand.h"
#include <ctime>
#include <cmath>



MyRand::MyRand() : a (691), c (1901), mod (3571),	d (163),
				prev1 (time(NULL) % 10000), prev2 (time(NULL) % 10000)
{

}

double MyRand::linearCongruent()
{
	now = (a*int(prev1) + c) % mod;
	renew();
	return now;
}

double MyRand::quadraticLinearCongruent()
{
	now = (d*int(prev1)* int(prev1) + a*int(prev1) + c) % mod;
	renew();
	return now;
}

double MyRand::fibonachi()
{
	now = (int(prev1) + int(prev2)) % mod;
	renew();
	return now;
}

double MyRand::invertCongruent()
{
	now = (a*invert(prev1, mod) + c) % mod;
	renew();
	return now;
}

double MyRand::unification()
{
	now = (int(linearCongruent()) - int(quadraticLinearCongruent())) % mod;
	return now;
}

double MyRand::sigmaRule()
{
	now = sum() - 6;
	return now;
}

double MyRand::polarCoordinates()
{
	if (status)
	{
		double static s, v1, v2;
		do 
			s = pow(v1 = vFind(), 2) + pow(v2 = vFind(), 2);
		while (s < 1);
		now = xFind(v1, s);
		prev = xFind(v2, s);
		status = false;
	} else return prev;
	return now;
}

MyRand::~MyRand()
{

}

int MyRand::invert(int num, int mod)
{
	int i = 0;
	while ((num*i) % mod != 1) i++;
	return i;
}

void MyRand::renew()
{
	prev2 = prev1;
	prev1 = now;
}

double MyRand::vFind()
{
	return 2 * linearCongruent() - 1;
}

double MyRand::xFind(double num1, double num)
{
	return num1 * sqrt((-2*log(num))/num);
}

double MyRand::sum()
{
	double result = 0;
	for (int i = 0; i < 12; ++i) result += fibonachi() / double(mod);
	return result;
}
