#include <iostream>
#include "func.h"

using namespace std;

double gaussdet (double** mat, int n)//metod gaussa
{
	for (int k = 0;k < n - 1;++k)//cikl dlya vybora vedushei stroki
	{
		double el_0 = mat[k][k];//vedushii element v stroke
		for (int i = k + 1; i < n; ++i)//cikl po strokam nizhe
		{
			double den_c = mat[i][k];//vedushii element v tekushei stroke
			for (int j = 0; j < n; ++j)//cikl po elementam v stroke
				mat[i][j] = mat[i][j] - mat[k][j]*den_c/el_0;
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl; //vyvod treugol'noi matricy -- dlya proverki 

	double det = 1;

	for (int k = 0; k < n; k++)
	{
		det *= mat[k][k];//opredelitel', proizvedenie elementov diagonali
	}

	return det;
}