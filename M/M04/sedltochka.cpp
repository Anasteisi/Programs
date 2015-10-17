#include <ctime>
#include <iostream>
#include <cstring>
#include "func.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "RUS");
	srand(time(NULL));
	int m, n;
	cout << "Vvedite kolichestvo strok: " << endl;
	cin >> m;
	cout << "Vvedite kolichestvo stolbcov: " << endl;
	cin >> n;

	int **mat = new int *[m];

	cout << "Matrica: " << endl;

	for (int i = 0; i < m; ++i)
	{
		mat[i] = new int[n];//massiv

		for (int j = 0; j < n; ++j)
		{
			mat[i][j] = rand() % 10;//zapolnenie massiva
			cout << mat[i][j] << " ";//matrica
		}
		cout << endl;
	}

	cout << endl;
	sedlovtoch(mat, m, n);

	for (int i = 0; i < m; ++i)
		delete[] mat[i];
	delete[]mat;
	system("pause");
	return 0;
}