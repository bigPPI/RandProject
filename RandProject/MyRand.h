#pragma once
class MyRand
{
public:
	MyRand();
	double linearCongruent();
	double quadraticLinearCongruent();
	double fibonachi();
	double invertCongruent();
	double unification();
	double sigmaRule();
	double polarCoordinates();
	~MyRand();
private:
	int a, c, mod, d;
	double prev1, prev2, now, prev;
	bool status = true;
	int invert(int num, int mod);
	void renew();
	double vFind();
	double xFind(double num1, double num2);
	double sum();
};

