#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

char *arab2rim(int arab) //funkcia dlya perevoda arabskogo chisla v rimskoe
{
	const int arabs[] = { 1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000 };//massiv arabskih chisel
	const char *rims[] = { "I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M" };//massiv rimskih chisel, massiv strok = 2-hmerniy massiv simvolov

	static char rim[20];//massiv dlya otveta

	int n = sizeof(arabs) / sizeof(int) - 1;//kolichestvo elementov v massive arabs (schet s 0)
	int arabmax = arabs[n];//samoe bolshoe arabskoe chislo - 1000
	const char rimmax = rims[n][0];//1000=M

	int i = 0;;//schetchik kolishestva elementov v massive-otvete

	while (arab>arabmax) //poka iznachal'noe chislo bolshe 1000
	{
		rim[i++] = rimmax;//kolichestvo tysyach*M
		arab -= arabmax;//minus 1000
	}

	while (arab > 0)
	{
		if (arab >= arabs[n])//>=n-go elementa massiva arabs
		{
			rim[i++] = rims[n][0];// i-i element otveta rim = n-i element massiva rims
			if (n & 1)//chetnost' pozicii
				rim[i++] = rims[n][1];//2 element rimzkoi cifry
			arab -= arabs[n];//minus n-i element arabs
		}
		else
			n--;//sledujushii element (po ubyvaniyi)
	}

	rim[i] = 0;//posledniy element stroki
	return rim;//otvet
}

int main()
{
	char str[100];//stroka

	ifstream in("in.txt");//fail
	if (!in.is_open())
	{
		cout << "Read file Error!" << endl;//ne otkryvaetsya
		system("pause");
		return 1;//zavershit' programmu
	}

	ofstream out;
	out.open("out.txt");//otkryrie faila dlya zapisi
	if (!out.is_open())
	{
		cout << "Write file Error!" << endl;//ne otkryvaetsya
		system("pause");
		return 1;//zavershit' programmu
	}

	while (!in.eof())//poka ne konec faila
	{
		in.getline(str, 100);//stroka
		char *context;//otslezhivayet, kakoe slovo chitaetsya, dlya povtornogo vyzova
		char *sl = strtok_s(str, " ", &context);//slovo do " "

		while (sl != NULL)//poka ne konec stroki 
		{
			if (strlen(sl) == 10 && sl[2] == '.' && sl[5] == '.')//slovo iz 10 simvolov
			{
				char den[3] = { sl[0], sl[1], '\0' };
				char mes[3] = { sl[3], sl[4],'\0' };
				char god[5] = { sl[6], sl[7], sl[8], sl[9], '\0' };

				int arab = atoi(god);//god -> chislo

				if (atoi(den) <= 31 && atoi(mes) <= 12 && arab != 0)//31 den, 12 mes, god -- chislo, ne 0
				{
					char *rim;//god rimskimi ciframi
					rim = arab2rim(arab);//funkcia
					out << den << "." << mes << "." << rim << " ";
				}
				else
					out << sl << " ";//ne data, bez izmenenii
			}
			else
				out << sl << " ";// ne 10, bez izmenenii
			sl = strtok_s(NULL, " ", &context);//sledujushee slovo
		}
		out << endl;//novaya stroka
	}

	out.close();//zakrytie faila
	in.close();//zakrytie faila

	system("pause");
	return 0;
}