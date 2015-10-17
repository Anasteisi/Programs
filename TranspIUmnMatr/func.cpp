#include <iostream>
#include "func.h"

using namespace std;

void printm(int **matr, int a, int b)//vyvod
{
	for (int i = 0; i < a; ++i)
	{
		for (int j = 0; j < b; ++j)
		{
			cout << matr[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;
}

void transp(int** matr1, int m, int n)//matr^t
{
	int **trmat = new int *[n];

	for (int i = 0; i < n; ++i)
	{
		trmat[i] = new int[m];//matr^t n*m
		for (int j = 0; j < m; ++j)
			trmat[i][j] = matr1[j][i];//zapolnenie massiva
	}

	printm(trmat, n, m);//vyvod
}

int proizvmatrs(int** matr1, int** matr2, int m, int n, int p)//matr1*matr2
{
	int **matr12 = new int *[m];

	for (int i = 0; i < m; ++i)
	{
		matr12[i] = new int[p];//massiv dlya matr1*matr2 m*p
		for (int j = 0; j < p; j++)
		{
			int s = 0;//obnulenie peremennoi
			for (int r = 0; r < n; r++)
				s += matr1[i][r] * matr2[r][j];//formula
			matr12[i][j] = s;//zapolnenie massiva
		}
	}

	printm(matr12, m, p);//vyvod
	return 0;
}