#include <iostream>
#include <cmath>

using namespace std;

unsigned long long fact(unsigned int x)
{
	long res = 1;

	for (int i = 1; i <= x; i++)
	{
		res = res * i;
	}

	return res;
}

double myPow(double x, int n)
{
	double res = 1;

	for (int i = 1; i <= abs(n); i++)
	{
		res = res * x;
	}

	if (n < 0)
	{
		return 1 / res;
	}

	return res;
}

double mySin(double x, double e)
{
	double res = x;
	double sum = x;
	int i = 1;

	while (fabs(sum) > e)
	{
		sum *= (-(x * x)) / ((2 * i) * (2 * i + 1));
		res = res + sum;
		i++;
	}

	return res;
}

double myExp(double x, double n)
{
	double sum = 1;


	for (int i = 1; i <= n; i++)
	{
		sum = sum + myPow(x, i) / fact(i);
	}

	return sum;
}

double myCos(double x, double e)
{
	double res = 0;
	double sum = 1;
	int k = 0;

	while (fabs(sum) > e)
	{
		sum = myPow(-1, k) * myPow(x, 2 * k) / fact(2 * k);
		res = res + sum;
		k++;
	}

	return res;
}



int main()
{
	cout << "My sin(3): " << mySin(3, 0.001) << endl;
	cout << "CMATH sin(3): " << sin(3) << endl << endl;

	cout << "My exp(1, 10): " << myExp(1, 10) << endl;
	cout << "CMATH exp(1): " << exp(1) << endl << endl;

	cout << "My cos(2): " << myCos(5, 0.00001) << endl;
	cout << "CMATH cos(2): " << cos(5) << endl;

	return 0;
}
