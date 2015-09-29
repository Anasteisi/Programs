#include <iostream>
#include "cmath"
using namespace std;

int main()
{
	setlocale(LC_ALL, "RUS");
	int a, b, c; //коэффициенты
	double d, x1, x2; //дискриминант, x1 x2 при d>0

	cout << "Введите коэффициенты a, b, c: " << endl;
	cin >> a >> b >> c;

	if ((a == 0) && (b == 0))
	{
		if (c != 0)
			cout << "Ошибка!" << endl; //0!=0
		else
			cout << "x -- любое." << endl; //0=0
	}

	else
	{
		if (a == 0)

		{
			cout << "Уравнение не квадратное." << endl; //bx+c=0
			cout << "x=" << (-c / b) << endl;
		}

		else
		{
			d = (b*b - 4*a*c); //дискриминант

			if (d < 0)
				cout << "Нет вещественных корней." << endl; //d<0
			else
			{
				if (d == 0)
					cout << "x=" << -b / (2 * a) << endl;//1 корень при d=0

				else
				{
					x1 = (-b - sqrt(d)) / (2 * a);
					x2 = (-b + sqrt(d)) / (2 * a);

					cout << "x1=" << x1 << endl;
					cout << "x2=" << x2 << endl;
				}
			}
		}
	}
	system("pause");
	return 0;
}