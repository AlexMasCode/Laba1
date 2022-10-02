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

// Область визначення (-32; 32). Точніше рядом Тейлора визначити не можливо, треба використовувати більш складніші і точнші формули та ряди.
double mySin(double x, double e)
{
	double res = x;
	double sum = x;
	int i = 1;
	int k = 0;

	while (fabs(sum) > e)
	{
		sum *= -x * x / ((2 * i) * (2 * i + 1));
		res = res + sum;
		i++;
	}

	return res;
}

// Область визначення (-9; 707). Точніше рядом Тейлора визначити не можливо, треба використовувати більш складніші і точнші формули та ряди.
double myExp(double x, double eps)
{
	double sum = 1;

	int i = 1;
	double m = 1;

	while (fabs(m) >= eps)
	{
		m = m * x / i++;
		sum = sum + m;
	}

	return sum;
}

// Область визначення (-35; 34). Точніше рядом Тейлора визначити не можливо, треба використовувати більш складніші і точнші формули та ряди.
double myCos(double x, double e)
{
	double sum = 1;
	double res = sum;
	int k = 0;

	do {
		sum *= -x * x / ((2 * k + 1) * (2 * k + 2));
		res += sum;
		k++;

	} while (abs(sum) > e);

	return res;
}



int main()
{
	cout << "SIN" << endl;

	for (double i = -35; i < 35; i += 1)
	{
		cout << i << " - mySin = " << mySin(i, 0.0000001) << endl;
		cout << i << " - cmath Sin = " << sin(i) << endl << endl;
	}
	
	cout << "EXP" << endl;

	for (double i = -9; i <= 707; i += 1)
	{
		cout << i << " - myExp = " << myExp(i, 0.0000001) << endl;
		cout << i << " - cmath exp = " << exp(i) << endl << endl;
	}

	cout << "COS" << endl;
	for (double i = -40; i < 40; i += 1)
	{
		cout << i << " - myCos = " << myCos(i, 0.0000001) << endl;
		cout << i << " - cmath Cos = " << cos(i) << endl << endl;
	}

	return 0;
}
