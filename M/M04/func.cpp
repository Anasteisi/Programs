#include <iostream>
#include "func.h"

using namespace std;

void sedlovtoch(int** mat, int m, int n)//poisk sedlovoi tochki
{
	int istbminstr = 0;//index stolbca min elementa v stroke
	int istrmaxstb = 0;//index stroki max elementa v stolbce
	bool q = true;//dlya proverki nalichija tochek
	int s = 1;//kolichestvo sedlovyh tochek

	for (int i = 0; i < m; i++)//stroka
	{
		for (int j = 0; j < n; j++)//stolbec
		{
			if (mat[i][j] < mat[i][istbminstr])
				istbminstr = j;//index stolbca pervogo min elementa v stroke
		}

		for (int j = 0; j < n; j++)//stolbec
		{
			if (mat[i][j] == mat[i][istbminstr])
			{
				istbminstr = j;
				istrmaxstb = i;

				for (int k = 0; k < m; k++)//stroka
				{
					if (mat[k][j] > mat[istrmaxstb][j])
						istrmaxstb = k;
				}

				if (istrmaxstb == i)//ne izmenilsya
				{
					cout << s << ". Sedlovaya tochka: " << mat[istrmaxstb][istbminstr] << ", eyo koordinaty -- [" << istrmaxstb << "][" << istbminstr <<"]." << endl;
					q = false;//est' minimum 1 tochka
					s++;
				}
			}
		}
	}

	if (q==true)//ne izmenilos'
	cout << "Sedlovyh tochek v matrice net." << endl;
}