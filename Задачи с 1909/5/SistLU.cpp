#include <iostream>
#include "cmath"
using namespace std;

int main()
{
	setlocale(LC_ALL, "RUS");

	double m[2][2] = { 0 }; //матрица из коэффициентов A1 B1 A2 B2
	double n[2][1] = { 0 }; //столбец из свободных членов C1 C2
	double x, y; //корни уравнений

	cout << "Введите коэффициенты уравнений " << endl;
	cout << "A1x+B1y+C1=0 и A2x+B2y+C2=0 " << endl;
	cout << "в порядке " << endl;
	cout << "A1, B1, A2, B2" << endl;

	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			cin >> m[i][j]; //матрица 2*2 (A1 B1) (A2 B2) -- строки

	cout << "Введите свободные члены уравнений " << endl;
	cout << "A1x+B1y+C1=0 и A2x+B2y+C2=0 " << endl;
	cout << "в порядке " << endl;
	cout << "C1, C2" << endl;

	for (int i = 0; i < 2; i++)
		cin >> n[i][0]; //столбец (-C1 -C2)

	for (int i = 0; i < 2; i++)
		n[i][0]=-n[i][0]; //Ax+By+C=0 => Ax+By=-C -- смена знака у C1 C2 для формирования столбца (C1 C2)

	if (((m[0][0]==0) && (m[0][1]==0) && (n[0][0] != 0)) || ((m[1][0] == 0) && (m[1][1] == 0) && (n[1][0] != 0)))
		cout << "Ошибка!" << endl; //0x+0y+c=0 => c=0

	else
	{
		double det = m[0][0] * m[1][1] - m[0][1] * m[1][0]; //определитель главной матрицы
		double det1 = n[0][0] * m[1][1] - m[0][1] * n[1][0];//определитель матрицы с 1 столбцом (C1 C2)
		double det2 = m[0][0] * n[1][0] - n[0][0] * m[1][0]; //определитель матрицы с 2 столбцом (C1 C2)

		if (det == 0)

		{
			if ((det1!=0) || (det2!=0))
			cout << "Система несовместна, решений нет." << endl; //det=0, det1||det2!=0
		    else
			cout << "Система имеет бесконечное множество решений." << endl;//det=det1=det2=0
		}

		else
		{
			x = det1 / det;
			y = det2 / det;
			cout << "x=" << x << ", y=" << y << endl;
		}
	}
	system("pause");
	return 0;
}