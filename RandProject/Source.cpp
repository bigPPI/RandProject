#include<iostream>

using namespace std;

void linearCongruent(int arr[])
{
	int a = 691, c = 1901, m = 3571;
	arr[0] = rand() % 11;
	for (int i = 1; i < 100; ++i) {
		arr[i] = (a*arr[i - 1] + c) % m;
	}
}

void quadraticLinearCongruent(int arr[])
{
	int d = 163, a = 691, c = 1901, m = 3571;
	arr[0] = rand() % 11;
	for (int i = 1; i < 100; ++i) {
		arr[i] = (d*arr[i - 1] * arr[i - 1] + a*arr[i - 1] + c) % m;
	}
}

int buffer(int arr[], int i, int type)
{
	int t = (arr[i] % 100);
	switch (type) {
	case 1:
		return t / 100.0 * 10;
	case 2:
		return t / 16.5 / 0.6;
	case 3:
		return t / 10;
	}
}

void splitIntoIntervals(int arr[], double result[], int type)
{
	for (int i = 0; i < 100; ++i)
		++result[buffer(arr, i, type)];
	result[9] += result[10];
	for (int i = 0; i < 10; ++i)
		result[i] /= 100;
}

int main()
{
	int arr1[100], arr2[100];
	double result[11] = { 0 };
	linearCongruent(arr1);
	linearCongruent(arr2);
	splitIntoIntervals(arr1, result, 2);
	for (int i = 0; i < 10; ++i) {
		cout << result[i] << endl;
	}
	splitIntoIntervals(arr2, result, 2);
	for (int i = 0; i < 10; ++i) {
		cout << result[i] << endl;
	}
	system("pause");
	return 0;
}