#include <iostream>
#include <ctime>
#include <cstring>

using namespace std;

int decTok(char *s, int k)//Perevod is 10i v kju (k = 2...9)
{
	int dec = atoi(s);//10-e chislo

	int ch = 0;//chastnoe
	int ost = 0;//ostatok
	int m = 1;//razryad
	int rez = 0;//otvet

	while (dec != 0)//algoritm
	{
		ch = dec / k;
		ost = dec - ch * k;
		rez += ost*m;
		m *= 10;
		dec = ch;
	}
	return rez;
}

int main()

{
	srand(time(NULL));
	setlocale(LC_ALL, "RUS");

	char s[32];
	int k = 0;

	cout << "Vvedite desyatichnoe chislo i nuzhnuyu sistemu schisleniya (ot 2 do 9): " << endl;
	cin >> s >> k;

	int rez = decTok(s, k);
	cout << "Shislo " << s << " v " << k << "i sisteme schisleniya = " << rez << endl;

	system("pause");
	return 0;
}
