#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double h(const double x);

int main()
{
	double qp, qk, z;
	int n;

	cout << "qp = "; cin >> qp;
	cout << "qk = "; cin >> qk;
	cout << "n = "; cin >> n;

	double dq = (qk - qp) / n;
	double q = qp;

	cout << fixed;
	cout << "-----------------------------" << endl;
	cout << "|" << setw(7) << "q" << " |"
		<< setw(10) << "z" << " |"
		<< setw(5) << "n" << " |"
		<< endl;
	cout << "-----------------------------" << endl;

	while (q <= qk)
	{

		z = h(q + 1) + h(pow(q, 2) + 1) + h(pow(q, 2) * h(pow(q, 2)));
		
		q += dq;

		cout << "|" << setw(7) << setprecision(2) << q << " |"
			<< setw(10) << setprecision(5) << z << " |"
			<< setw(5) << n << " |"
			<< endl;
	}
	cout << "-----------------------------" << endl;
	return 0;

}

double h(const double x)
{
	if (abs(x) >= 1)
	{
		return (cos(x) + 1) / (pow(cos(x),2) + 1);
	}
	else
	{
		double S = 0;
		int i = 0;
		double a = 1;
		S = a;
		double k ;
		k = 1 / cos(x);
		double p = 0;
		do
		{
			i++;
			double R = pow(x,2*i)/ ((2 * i - 1) * 2 * i );
			a *= R;
			S += a;
		} while (i < 6);
		p = k * S;
		return p;

	}
}