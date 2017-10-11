#pragma once
#include <vector>
using namespace std;

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
	double correlation();
	double logarithm();
	double Arenths();
	double getMod();
	~MyRand();
private:
	int a, c, mod, d;
	double prev1, prev2, now, now1, prev;
	bool status = true;
	int invert(int num, int mod);
	/*double (*randomFunctions[10])()
	vector <double (MyRand::*) ()> randomFunctions = {&MyRand::linearCongruent, &MyRand::quadraticLinearCongruent,
		&MyRand::fibonachi, &MyRand::invertCongruent, &MyRand::unification, &MyRand::sigmaRule,
		&MyRand::polarCoordinates, &MyRand::correlation, &MyRand::logarithm, &MyRand::Arenths};*/
	void renew();
	double vFind();
	double xFind(double num1, double num2);
	double sum();
};

