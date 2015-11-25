#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

char *arab2rim(int arab) //funkcia dlya perevoda arabskogo chisla v rimskoe
{
	const int arabs[] = { 1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000 };//massiv arabskih chisel
	const char *rims[] = { "I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M" };//massiv rimskih chisel

	static char rim[20];//massiv dlya otveta

	int m = sizeof(arabs) / sizeof(int) - 1;//kolichestvo elementov v massive arabs (schet s 0)
	int arabmax = arabs[m];//samoe bolshoe arabskoe chislo - 1000
	const char rimmax = rims[m][0];//1000=M

	int i = 0;;//schetchik kolishestva elementov v massive-otvete
	int n;//peremennaya dlya vybora elementa arabs/rims

	while (arab>arabmax) //poka iznachal'noe chislo bolshe 1000
	{
		rim[i++] = rimmax;//kolichestvo tysyach*M
		arab -= arabmax;//minus 1000
	}

	n = m;//kolichestvo elementov v massive arabs (schet s 0)

	while (arab > 0)
	{
		if (arab >= arabs[n])//>=n-go elementa massiva arabs
		{
			rim[i++] = rims[n][0];// i-i element otveta rim = n-i element massiva rims
			if (n & 1)
				rim[i++] = rims[n][1];
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
	char str[32];//stroka do ' '

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

	while (!in.eof())//poka ne konec in
	{
		in >> str;//stroka do ' '
		if (strlen(str) == 10 && str[2] == '.' && str[5] == '.')//stroka iz 10 simvolov vida aa.bb.cccc
		{
			char den[3] = { str[0], str[1],'\0' };
			char mes[3] = { str[3], str[4],'\0' };
			char god[5] = { str[6], str[7], str[8], str[9], '\0' };

			if (atoi(den) <= 31 && atoi(mes) <= 12)//31 den, 12 mes
			{
				char *rim;//god rimskimi ciframi
				int arab = atoi(god);//god -> chislo
				if (arab != 0)//chislo, ne 0
				{
					rim = arab2rim(arab);//funkcia
					out << den << "." << mes << "." << rim << endl;
				}
				else out << den << "." << mes << "." << god << endl;//bez izmenenii
			}
			else
				out << str << endl;//bez izmenenii
		}
		else
			out << str << endl;//bez izmenenii
	}

	out.close();//zakrytie faila
	in.close();//zakrytie faila

	system("pause");
	return 0;
}