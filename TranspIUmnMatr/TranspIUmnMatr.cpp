#include <ctime>
#include <iostream>
#include <cstring>
#include "func.h"

using namespace std;

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "RUS");
	srand(time(NULL));
	int m, n, o, p;

	m = atoi(argv[1]);//m -- kolichestvo strok matr1
	n = atoi(argv[2]);//n -- kolichestvo stolbcov matr1
	o = atoi(argv[3]);//o -- kolichestvo strok matr2
	p = atoi(argv[4]);//p -- kolichestvo stolbcov matr2

	int **matr1 = new int *[m];
	for (int i = 0; i < m; ++i)
	{
		matr1[i] = new int[n];//pervaya matrica m*n
		for (int j = 0; j < n; ++j)
			matr1[i][j] = rand() % 10;//zapolnenie massiva
	}

	int **matr2 = new int *[o];
	for (int i = 0; i < o; ++i)
	{
		matr2[i] = new int[p];//vtoraya matrica o*p
		for (int j = 0; j < p; ++j)
			matr2[i][j] = rand() % 10;//zapolnenie massiva
	}

	cout << "������� 1: \n" << endl;
	printm(matr1, m, n);

	cout << "����������������� ������� 1: \n" << endl;
	int** trmat = transp(matr1, m, n);
	printm(trmat, n, m);

	cout << "������� 2: \n" << endl;
	printm(matr2, o, p);

	if (n != o)
		cout << "������� 1 ���������� �������� �� ������� 2!" << endl;//kol-vo stb matr1 != kol-vu srt matr2
	else
	{
		cout << "������� 1 * ������� 2: \n" << endl;
		int** matr12 = proizvmatrs(matr1, matr2, m, n, p);
		printm(matr12, m, p);

		for (int i = 0; i < m; ++i)
			delete[] matr12[i];
		delete[]matr12;//ochistka pamyati
	}

	for (int i = 0; i < m; ++i)
		delete[] matr1[i];
	delete[]matr1;//ochistka pamyati

	for (int i = 0; i < o; ++i)
		delete[] matr2[i];
	delete[]matr2;//ochistka pamyati

	for (int i = 0; i < n; ++i)
		delete[] trmat[i];
	delete[]trmat;//ochistka pamyati

	system("pause");
	return 0;
}