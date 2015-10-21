#include <ctime>
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	setlocale(LC_ALL, "RUS");
	double x1, x2, eps, dx;
	cout << "Vvedite X1" << endl;
	cin >> x1;
	if ((x1 > 2)||(x1 <= 0))
		cout << "Oshibka! X1 ne prinadlezhit oblasti opredelenija funkcii." << endl;//(0;2]
	else
	{
		cout << "Vvedite X2" << endl;
		cin >> x2;
		if ((x2 > 2) || (x2 <= 0))
			cout << "Oshibka! X2 ne prinadlezhit oblasti opredelenija funkcii." << endl;//(0;2]
		else
		{
			cout << "Vvedite tochnost' vychisleniy" << endl;
			cin >> eps;//min |ocerednoe slagaemoe|
			if ((eps <= 0) || (eps > 1))
				cout << "Oshibka!" << endl;//0<eps<=1
			else
			{
				cout << "Vvedite shag" << endl;
				cin >> dx;//shag x

				cout << "x" << "\t" << "y" << endl;

				x1 = x1 + dx;//pervoe x, t. k. (x1;x2) -- interval

				while (x1 < x2) //(x1;x2)
				{
					double a = x1 - 1;//pervoe slagaemoe
					double sum = 0;//summa vseh chlenov do eps vkl
					int n = 1;//schetchik (s 1, t.k. n=0 uzhe uchteno v a)

					while (abs(a) >= eps)
					{
						sum += a;
						a = (pow(-1, n)*pow((x1 - 1), (n + 1))) / (n + 1);//ocherednoe slagaemoe
						n++;//schetchik
					}

					cout << x1 << "\t" << sum << endl;
					x1 = x1 + dx;//shag
				}
			}
		}
	}
	system("pause");
	return 0;
}