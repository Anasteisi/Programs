#include <iostream>
#include "cmath"
using namespace std;

int main()
{
	setlocale(LC_ALL, "RUS");
	const double PI = 3.1415926535897932384626433832795;
	double a, z1, z2;

	cout << "������� ���� alpha � ��������: " << endl;
	cin >> a;

	a = (a * PI / 180); //���� � ��������
	double znam1 = 1 + sin(2 * a); // ����������� ������ �����
	double znam2 = 1 + tan(a); //����������� ������ �����

	if (znam1 == 0)
	{
		if (znam2 == 0)
			cout << "z1 � z2 �� ����������" << endl; // ����������� =0
		else
		{
			cout << "z1 �� ����������" << endl; //����������� ������ ����� =0
			z2 = (1 - tan(a)) / znam2;
			cout << "z2=" << z2 << endl;
		}
	}

	else
	{
		if (znam2 == 0)
		{
			z1 = (1 - 2 * sin(a) * sin(a)) / znam1;
			cout << "z1=" << z1 << endl;
			cout << "z2 �� ����������" << endl; //����������� ������ ����� =0
		}
		else
		{
			z1 = (1 - 2 * sin(a) * sin(a)) / znam1;
			z2 = (1 - tan(a)) / znam2;
			cout << "z1=" << z1 << endl;
			cout << "z2=" << z2 << endl;
		}
	}

	system("pause");
	return 0;
}