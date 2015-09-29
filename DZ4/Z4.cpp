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
	if ((x1>2)||(x1<0)||(x1==0))
		cout << "Oshibka! X1 ne prinadlezhit oblasti opredelenija funkcii." << endl;//(0;2]
	else
	{
		cout << "Vvedite X2" << endl;
		cin >> x2;
		if ((x2 > 2) || (x2 < 0) || (x2 == 0))
			cout << "Oshibka! X2 ne prinadlezhit oblasti opredelenija funkcii." << endl;//(0;2]
		else
		{
			cout << "Vvedite tochnost' vychisleniy" << endl;
			cin >> eps;//|ocerednoe slagaemoe|
			if ((eps < 0) || (eps > 1))
				cout << "Oshibka!" << endl;//0<=eps<=1
			else
			{
				cout << "Vvedite shag" << endl;
				cin >> dx;//shag x
				cout << "x" << "\t" << "y" << endl;

				while (x1 < (x2 - dx))//(x1;x2)
				{
					x1 = x1 + dx;//shag
					double a = 0;//osherednoe slagaemoe
					double sum = 0;//summa vseh chlenov do eps vkl
					int n = 0;//schetchik
					a = x1 - 1;//pervoe slagaemoe
					while ((abs(a)>eps) || (abs(a) == eps))
					{
							sum = sum + a;
							n++;//schetchik (s 1, t.k. n=0 uzhe uchteno v a)
							a = (pow(-1, n)*pow((x1 - 1), (n + 1))) / (n + 1);//ocherednoe slagaemoe
					}
					cout << x1 << "\t" << sum << endl;
				}
			}
		}
	}
	system("pause");
	return 0;
}