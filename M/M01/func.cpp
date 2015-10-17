#include <iostream>
#include "func.h"

using namespace std;

void gauss(double** mat, int n)//metod gaussa
{
	for (int k = 0;k < n - 1;++k)//cikl dlya vybora vedushei stroki
	{
		double el_0 = mat[k][k];//vedushii element v stroke
		for (int i = k + 1; i < n; ++i)//cikl po strokam nizhe
		{
			double den_c = mat[i][k];//vedushii element v tekushei stroke
			for (int j = 0; j < n; ++j)//cikl po elementam v stroke
				mat[i][j] = mat[i][j] * el_0 / den_c - mat[k][j];
		}
	}
}

void printm(double**mat, int n)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

