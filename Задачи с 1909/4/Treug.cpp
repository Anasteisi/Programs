#include <iostream>
#include "cmath"
using namespace std;

int main()
{
	setlocale(LC_ALL, "RUS");
	int x1, y1, x2, y2, x3, y3; //координаты  A, B, C соответственно

	cout << "Введите координаты точки А: " << endl;
	cin >> x1 >> y1 ;
	cout << "Введите координаты точки B: " << endl;
	cin >> x2 >> y2;
	cout << "Введите координаты точки C: " << endl;
	cin >> x3 >> y3;
	
	double a, b, c, p, s; // длины сторон BC, AC, AB, периметр и площадь соответственно

	a = sqrt((x3 - x2)*(x3 - x2) + (y3 - y2)*(y3 - y2)); //длина стороны BC
	b = sqrt((x3 - x1)*(x3 - x1) + (y3 - y1)*(y3 - y1)); //длина стороны AC
	c = sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1)); //длина стороны AB

	p = a + b + c; //периметр

	double pp = p / 2; //полупериметр, для формулы Герона
	s = sqrt(pp*(pp - a)*(pp - b)*(pp - c)); //площадь по формуле Герона
	
	if (s == 0)

		cout << "Точки A, B и C лежат на одной прямой." << endl; //s=0,5 основания на высоту=0 => прямая
	
	else
	{
		cout << "Площадь треугольника ABC = " << s << endl;
		cout << "Периметр треугольника ABC = " << p << endl;
	}

	system("pause");
	return 0;
}