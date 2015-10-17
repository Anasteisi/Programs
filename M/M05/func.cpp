#include <iostream>
#include "func.h"

using namespace std;

void krnol(int** mat, int m, int n, int k)
{
	int s = 1;//kolichestvo X podryad
	bool rez = false;//peremennaya dlya proverki nalichiya vyigryshnoi kombinacii

	if (k == 1)//trivial'nyi slychai
	{
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (mat[i][j] == 1)
					rez = true;
			}
		}
	}
	
	for (int i = 0; i < m; i++)//cikl po strokam
	{
		for (int j = 0; j < n - 1; j++)//stolbec
		{
			if (mat[i][j] == 1 && mat[i][j + 1] == 1)//dva X podryad
			{
				s++;
				if (s >= k)
					rez = true;//pobeda
			}
			else
				s = 1;//sbros schetchika
		}
	}

	for (int j = 0; j < n; j++)//cikl po stolbcam
	{
		for (int i = 0; i < m - 1; i++)//stroka
		{
			if (mat[i][j] == 1 && mat[i  + 1][j] == 1)//dva X podryad
			{
				s++;
				if (s >= k)
					rez = true;//pobeda
			}
			else
				s = 1;//sbros schetchika
		}
	}

	for (int i = 0; i < m - 1; i++)//cikl po diagonalyam
	{
		for (int j = 0; j < n - 1; j++)//stolbec
		{
			if (mat[i][j] == 1 && mat[i + 1][j + 1] == 1)//dva X podryad v diagonali
			{
				s++;
				if (s >= k)
					rez = true;//pobeda
			}
			else
				s = 1;//sbros schetchika
		}
	}

	for (int i = 0; i < m - 1; i++)//cikl po obratnym diagonalyam
	{
		for (int j = n - 1; j > 0; j--)//stolbec
		{
			if (mat[i][j] == 1 && mat[i + 1][j - 1] == 1)//dva X podryad v obratnoi diagonali
			{
				s++;
				if (s >= k)
					rez = true;//pobeda
			}
			else
				s = 1;//sbros schetchika
		}
	}

	if (rez == true)
		cout << "Krestiki vyigrali!" << endl;
	else
		cout << "Krestiki proigrali." << endl;
}