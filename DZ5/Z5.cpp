#include <ctime>
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	setlocale(LC_ALL, "RUS");
	double k, p, r;

	cout << "Vvedite summu kredita" << endl;
	cin >> k;//summa
	cout << "Vvedite godovoi procent kredita" << endl;
	cin >> p;//procent
	p = p / 100;//procent v vide doli ot 1
	cout << "Vvedite ezhegodnuyu pribyl'" << endl;
	cin >> r;//pribyl'

	if (k*p >= r)
	cout << "Kredit vyplatit' nevozmozhno." << endl;//pribyl' men'she ili ravna summe procentov za 1 god ==> dolg ne bydet umen'shat'sya
	else
	{
		int i = 0;//schetchik let

		while (k>0)
		{
			k += k*p - r;//summa kredita + procenty za kazhdyi god
			i++;//+god
		}

		cout << "Kolichestvo let, neobhodimyh dlya pogasheniya kredita: " << i << endl;
	}
	system("pause");
	return 0;
}