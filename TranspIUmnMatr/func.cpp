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

int transp(int** matr1, int** trmat, int m, int n)//matr^t
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
			trmat[i][j] = matr1[j][i];
	}
	return **trmat;
}

int proizvmatrs(int** matr1, int** matr2, int ** matr12, int m, int n, int p)//matr1*matr2
{
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < p; j++)
		{
			int s = 0;//obnulenie peremennoi
			for (int r = 0; r < n; r++)
				s += matr1[i][r] * matr2[r][j];//formula
			matr12[i][j] = s;//zapolnenie massiva
		}
	}
	return **matr12;
}