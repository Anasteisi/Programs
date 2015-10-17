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

	
	double **mat = new double *[n];
	for (int i = 0; i < n; ++i)
	{
		mat[i] = new double[n];//matrica

		for (int j = 0; j < n; ++j)
		{
			mat[i][j] = rand() % 9 + 1;
			cout << mat[i][j] << " ";//vyvod matricy
		}
		cout << endl;
	}

	cout << endl;

	gauss(mat, n);//metod gaussa
	cout << "Treugol'naya matrica: " << endl;
	cout << endl;
	printm(mat, n);//vyvod treugolnoi matricy

	for (int i = 0; i < n; ++i)
		delete[] mat[i];
	delete[]mat;//ochistka pamyati

	system("pause");
	return 0;
}