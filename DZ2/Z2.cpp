#include <ctime>
#include <iostream>
#include <cstring>

using namespace std;
int main()
{
	setlocale(LC_ALL, "RUS");

	double x, n;
	double s = 0; //summa

	cout << "Vvedite x: " << endl;
	cin >> x;
	cout << "Vvedite n: " << endl;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		x = sin(x);//x=sin(x); x=sin(sin(x));...
		s = s + x;//sin(x)+sin(sin(x))+...
	}

	cout << "S=" << s << endl;

	system("pause");
	return 0;
}