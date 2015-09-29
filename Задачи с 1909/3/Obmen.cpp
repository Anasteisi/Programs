#include <iostream>
#include "cmath"
using namespace std;

int main()
{
	setlocale(LC_ALL, "RUS");
	int a, b;

	cout << "¬ведите a: " << endl;
	cin >> a;
	cout << "¬ведите b: " << endl;
	cin >> b;

	a = a - b; //a=x, b=y -- a=x-y
	b = a + b; // b=x-y+y=x
	a = b - a; // a=x-(x-y)=x-x+y=y

	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	system("pause");

	return 0;
}