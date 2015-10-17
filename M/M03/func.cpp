#include <iostream>
#include <cmath>
#include "func.h"

using namespace std;

void printm(double **matrx, int n)//vyvod matricy
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << matrx[i][j] << " ";
			cout << endl;
	}
}

double gaussdet(double** mat, int n)//metod gaussa
{
	for (int k = 0;k < n - 1;++k)//cikl dlya vybora vedushei stroki
	{
		double el_0 = mat[k][k];//vedushii element v stroke
		for (int i = k + 1; i < n; ++i)//cikl po strokam nizhe
		{
			double den_c = mat[i][k];//vedushii element v tekushei stroke
			for (int j = 0; j < n; ++j)//cikl po elementam v stroke
				mat[i][j] = mat[i][j] - mat[k][j] * den_c / el_0;
		}
	}

	/*for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl; //vyvod treugol'noi matricy -- dlya proverki */

	double det = 1;

	for (int k = 0; k < n; k++)
	{
		det *= mat[k][k];//opredelitel', proizvedenie elementov diagonali
	}
	return det;
}

double determinant(double **matrx, int n)//razlozhenie po stolbcy
{
	if (n == 1)//trivial'nyi sluchai
	{
		return matrx[0][0];
	}

	double sum = 0;
	double **minor;

	int decr = 0;

	for (int i = 0; i < n; i++)//vybor vedushego elementa v 0 stolbce
	{
		minor = new double *[n - 1];//minor dlya kazhdogo elementa v stolbce
		for (int j = 0; j < n; ++j)//cikl po strochkam
		{
			if (j == i)
			{
				decr = 1;
				continue;//propusk stroki s vedushim elementom
			}

			minor[j - decr] = new double[n - 1];//massiv dlya strok v minore, esli propustili stroku, to index dlya minora -- -1, t. k. on (n-1) razmera
			for (int k = 1; k < n; ++k)//cikl dlya dobavleniya stroki v minor , s 1, t. k. 0 stolbec vycherkivaem
			{
				minor[j - decr][k -1] = matrx[j][k];//zapolnenie massiva, k-1 -- t. k. numeracija s 0
			}
		}

		decr = 0;//oblulenie
		sum += matrx[i][0] * pow(-1, i+0)*determinant(minor, n - 1);//determinant(minor, n-1) -- vychislenie det minora

		for (int j = 0; j < n-1; ++j)
			delete[]minor[j];
		delete[]minor;
	}
	return sum;
}