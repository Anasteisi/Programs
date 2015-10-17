#include <ctime>
#include <iostream>
#include <cstring>
#include "func.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "RUS");
	srand(time(NULL));
	int m, n, k;
	cout << "Vvedite kolichestvo strok: " << endl;
	cin >> m;
	cout << "Vvedite kolichestvo stolbcov: " << endl;
	cin >> n;
	cout << "Vvedite k: " << endl;
	cin >> k;//kolichestvo X podryad dlya vyigrysha

	if (k > m && k > n)
		cout << "Vyigrat' nevozmozhno!" << endl;
	else
	{
		int **mat = new int *[m];

		cout << "Igrovoe pole: " << endl;
		cout << endl;

		for (int i = 0; i < m; ++i)
		{
			mat[i] = new int[n];//massiv

			for (int j = 0; j < n; ++j)
			{
				mat[i][j] = rand() % 2;//zapolnenie massiva
				if (mat[i][j] == 1)
					cout << "X";
				else
					cout << "0";//zapolnenie polya
			}
			cout << endl;
		}
		cout << endl;

		krnol(mat, m, n, k);//vyzov funckcii

		for (int i = 0; i < m; ++i)
			delete[] mat[i];
		delete[]mat;//ochistka pamyati
	}
	system("pause");
	return 0;
}