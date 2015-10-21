#include <ctime>
#include <iostream>
#include <cstring>

using namespace std;
int main()
{
	setlocale(LC_ALL, "RUS");
	double n; //tochnost'=|ocherednoe slagaemoe|
	cout << "Vvedite tichnost' vychisleniy" << endl;
	cin >> n;
	if (n > 1)
		cout << "Oshibka!" << endl;
	else
	{
		double a = 1, i = 0, pp = 0; //a - |ocherednoe slagaemoe|, b - schetchik, pp=0,25pi

		while (abs(a) >= n)
		{
			pp = pp + (pow(-1, i)) * a; //(-1)^i =+-1 (i chet/nechet), -1^0=1
			a = 1 / (2 * (i + 1) + 1); //|ocherendoe slagaemoe|
			i++;
		}
		cout << "Pi=" << pp * 4 << endl;
	}
	system("pause");
	return 0;
}