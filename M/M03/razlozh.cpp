#include <iostream>
#include <cmath>
#include <ctime>
#include "func.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "RUS");
	srand(time(NULL));

	int n = 0;
	cout << "Vvedite razmernost' matricy: " << endl;
	cin >> n;
	cout << endl;
	cout << "Matrica: " << endl;
	cout << endl;

	double **matrx = new double *[n];
	for (int i = 0; i < n; ++i)
	{
		matrx[i] = new double[n];//matrica

		for (int j = 0; j < n; ++j)
		{
			matrx[i][j] = rand() % 9 + 1;//zapolnenie
		}
	}

	printm(matrx, n);//vyvod
	cout << endl;

	double clock_t_start = clock();
	cout << "Method Gaussa: opredelitel' matricy = " << gaussdet(matrx, n) << endl;
	double clock_t_end = clock();
	double t1 = (clock_t_end - clock_t_start) / CLOCKS_PER_SEC;

	//cout << "Vremya vypolneniya = " << t1 << " sec " << endl;

	clock_t_start = clock();
	cout << "Razlozhenie po stolbcy: opredelitel' matricy = " << determinant(matrx, n) << endl;
	clock_t_end = clock();
	double t2 = (clock_t_end - clock_t_start) / CLOCKS_PER_SEC;

	//cout << "Vremya vypolneniya = " << t2 << " sec " << endl;

	cout << endl;

	if (t1 > t2)
		cout << "Razlozhenie po stolbcy effectivnee na " << t1 - t2 << " sec." << endl;//Gauss dol'she
	else
	{
		if (t1 == t2)
			cout << "Effectivnost' odinakova." << endl;
		else
			cout << "Method Gaussa effectivnee na " << t2 - t1 << " sec." << endl;//Razloahenie dol'she
	}

	for (int i = 0; i < n; ++i)
		delete[] matrx[i];
	delete[]matrx;//ochistka pamyati

	system("pause");
	return 0;
}