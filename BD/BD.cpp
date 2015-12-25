#include <ctime>
#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

struct ZapisBD
{
	char* Familia;//familia
	char* Imya;//imya
	char* Otshestvo;//otchestvo
	int GodR;//god rozhdeniya
	int ID;//unikal'nyi nomer

	ZapisBD()
	{
		Familia = nullptr;
		Imya = nullptr;
		Otshestvo = nullptr;
		GodR = 0;
		ID = 0;
	}
};

void ZapolnenieBD(char* Familia, char* Imya, char* Otshestvo, int GodR, int ID, ZapisBD& BD)
{
	int FL = strlen(Familia);//dlina elementa Familia
	if (BD.Familia == nullptr)//pustoi
	{
		BD.Familia = new char[FL + 1];//novaya stroka zadannoi dliny
		strcpy_s(BD.Familia, FL + 1, Familia);//kopirovanie Familia v BD.Familia
	}
	else
	{
		delete[] BD.Familia;//ochistit'
		BD.Familia = new char[FL + 1];
		strcpy_s(BD.Familia, FL + 1, Familia);
	}

	int IL = strlen(Imya);
	if (BD.Imya == nullptr)
	{
		BD.Imya = new char[IL + 1];
		strcpy_s(BD.Imya, IL + 1, Imya);
	}
	else
	{
		delete[] BD.Imya;
		BD.Imya = new char[IL + 1];
		strcpy_s(BD.Imya, IL + 1, Imya);
	}

	int OL = strlen(Otshestvo);
	if (BD.Otshestvo == nullptr)//pustoi
	{
		BD.Otshestvo = new char[OL + 1];
		strcpy_s(BD.Otshestvo, OL + 1, Otshestvo);
	}
	else
	{
		delete[] BD.Otshestvo;//ochistit'
		BD.Otshestvo = new char[FL + 1];
		strcpy_s(BD.Otshestvo, OL + 1, Otshestvo);
	}

	BD.GodR = GodR;
	BD.ID = ID;
}

void Menu1()
{/*
 cout << endl << "Deistvie:" << endl;
 cout << "Rabota s imejusheisya bazoi -- 1" << endl;
 cout << "Sozdanie novoi bazy -- 2" << endl;
 cout << "Zavershenie programmy -- lybaya drugaya klavisha" << endl << endl;
 */
	cout << endl << "Действие:" << endl;
	cout << "Работа с имеющейся базой -- 1" << endl;
	cout << "Создание новой базы -- 2" << endl;
	cout << "Завершение программы -- любая другая клавиша" << endl << endl;
}

void Menu2()
{/*
 cout << endl << "Dal'neishie deistviya:" << endl;
 cout << "Vyvesti bazu na ekran -- 1" << endl;
 cout << "Dobavit' novujy stroku -- 2" << endl;
 cout << "Udalit' stroku -- 3" << endl;
 cout << "Poisk zapisi -- 4" << endl;
 cout << "Sortirovat' dannye -- 5" << endl;
 cout << "Glavnoe menu -- 6" << endl;
 cout << "Zavershenie programmy -- lybaya drugaya klavisha" << endl << endl;
 */
	cout << endl << "Дальнейшие действия:" << endl;
	cout << "Вывести базу на экран -- 1" << endl;
	cout << "Добавить новую строку -- 2" << endl;
	cout << "Удалить строку -- 3" << endl;
	cout << "Поиск записи -- 4" << endl;
	cout << "Сортировать данные -- 5" << endl;
	cout << "Главное меню -- 6" << endl;
	cout << "Завершение программы -- любая другая клавиша" << endl << endl;
}

void Menu3SP()
{/*
 cout << endl << "Vyberite pole, po kotoromu sovershit' zadannoe deistvie:" << endl;
 cout << "Familia -- 1" << endl;
 cout << "Imya -- 2" << endl;
 cout << "Otchestvo -- 3" << endl;
 cout << "God rozhdeniya -- 4" << endl;
 cout << "ID -- 5" << endl;
 cout << "Glavnoe menu -- 6" << endl;
 cout << "Zavershenie programmy -- lybaya drugaya klavisha" << endl << endl;
 */
	cout << endl << "Выберите поле:" << endl;
	cout << "Фамилия -- 1" << endl;
	cout << "Имя -- 2" << endl;
	cout << "Отчество -- 3" << endl;
	cout << "Год рождения -- 4" << endl;
	cout << "ID -- 5" << endl;
	cout << "Главное меню -- 6" << endl;
	cout << "Завершение программы -- любая другая клавиша" << endl << endl;
}

void Menu4S()
{/*
 cout << endl << "Sortirovka po:" << endl;
 cout << "Alfavitu A--Z / Vozrastaniju 1-N -- 1" << endl;
 cout << "Alfavitu Z--A / Ubyvaniju N-1 -- 2" << endl;
 cout << "Glavnoe menu -- 3" << endl;
 cout << "Zavershenie programmy -- lybaya drugaya klavisha" << endl << endl;
 */
	cout << endl << "Сортировка по" << endl;
	cout << "Алфавиту A--Z / Возрастанию 1-N -- 1" << endl;
	cout << "Алфавиту Z--A / Убыванию N-1 -- 2" << endl;
	cout << "Главное меню -- 3" << endl;
	cout << "Завершение программы -- любая другая клавиша" << endl << endl;
}

void Error(char* filename)
{
	//cout << "Fail " << filename << " otkryt' nevozmozhno." << endl;
	cout << "Файл " << filename << " открыть невозможно." << endl;
	system("pause");
}

int KolStrok(fstream &fileBD)//kolichestvo strok v faile
{
	char str[255];
	int kstr = 0;
	while (!fileBD.eof())//poka ne konec faila
	{
		fileBD.getline(str, 256);//stroka
		kstr++;
	}
	return kstr;
}

void BDf(char* str, ZapisBD* BD, int i)//perevod stroki v strukturu
{
	char *context;//otslezhivayet, kakoe slovo chitaetsya
	char *Familia = strtok_s(str, " ", &context);//slovo do " "
	char* Imya = strtok_s(NULL, " ", &context);//sledujushee slovo
	char* Otshestvo = strtok_s(NULL, " ", &context);//sledujushee slovo
	char* sGodR = strtok_s(NULL, " ", &context);//sledujushee slovo
	char* sID = strtok_s(NULL, " ", &context);//sledujushee slovo

	int GodR = atoi(sGodR);//chislo
	int ID = atoi(sID);//chislo
	ZapolnenieBD(Familia, Imya, Otshestvo, GodR, ID, BD[i]);//zapolnenie
}

void PrintBD(ZapisBD* BD, int kstr)//vyvod bazy iz BD na ekran
{
	for (int i = 0; i < kstr; i++)
		cout << BD[i].Familia << " " << BD[i].Imya << " " << BD[i].Otshestvo << " " << BD[i].GodR << " " << BD[i].ID << endl;
}

void UdalZap(fstream &fileBD, ZapisBD* BD, int kstr, int keyID)//zapis v file vseh zapisei iz BD, krome keyID
{
	for (int i = 0; i < kstr - 1; i++)
	{
		if (BD[i].ID != keyID)
			fileBD << BD[i].Familia << " " << BD[i].Imya << " " << BD[i].Otshestvo << " " << BD[i].GodR << " " << BD[i].ID << endl;
	}
	if (BD[kstr - 1].ID != keyID)
		fileBD << BD[kstr - 1].Familia << " " << BD[kstr - 1].Imya << " " << BD[kstr - 1].Otshestvo << " " << BD[kstr - 1].GodR << " " << BD[kstr - 1].ID;
}

void ZapVF(fstream &fileBD, int kstr, char* str)//zapis' strok s konsoli v fail
{
	for (int i = 0; i < kstr - 1; i++)
	{
		cin.getline(str, 255);//stroka
		fileBD << str << endl;//zapis' v fail
	}
	cin.getline(str, 255);
	fileBD << str;//bez endl
}

void ZapBDVF(fstream &fileBD, ZapisBD* BD, int kstr)//zapis' strok iz BD v fail
{
	for (int i = 0; i < kstr - 1; i++)
	{
		fileBD << BD[i].Familia << " " << BD[i].Imya << " " << BD[i].Otshestvo << " " << BD[i].GodR << " " << BD[i].ID << endl;
	}
	fileBD << BD[kstr - 1].Familia << " " << BD[kstr - 1].Imya << " " << BD[kstr - 1].Otshestvo << " " << BD[kstr - 1].GodR << " " << BD[kstr - 1].ID;
}

void PoiskZapF(ZapisBD* BD, int kstr, char* key)//poisk zapisi v BD po familii
{
	bool rez = true;
	for (int i = 0; i < kstr; i++)
	{
		char* r = strstr(BD[i].Familia, key);//vhodit li key v BD[i].Familia
		if (r != nullptr)//da
		{
			cout << BD[i].Familia << " " << BD[i].Imya << " " << BD[i].Otshestvo << " " << BD[i].GodR << " " << BD[i].ID << endl;
			rez = false;
		}
	}
	if (rez == true)//net takih
		//cout << endl << "Zapis' ne naidena!" << endl << endl;
		cout << endl << "Запись не найдена!" << endl << endl;
}

void PoiskZapI(ZapisBD* BD, int kstr, char* key)//poisk zapisi v BD po imeni
{
	bool rez = true;
	for (int i = 0; i < kstr; i++)
	{
		char* r = strstr(BD[i].Imya, key);//vhodit li key v BD[i].Imya
		if (r != nullptr)//da
		{
			cout << BD[i].Familia << " " << BD[i].Imya << " " << BD[i].Otshestvo << " " << BD[i].GodR << " " << BD[i].ID << endl;
			rez = false;
		}
	}
	if (rez == true)//net takih
		//cout << endl << "Zapis' ne naidena!" << endl << endl;
		cout << endl << "Запись не найдена!" << endl << endl;
}

void PoiskZapO(ZapisBD* BD, int kstr, char* key)//poisk zapisi v BD po otchestvu
{
	bool rez = true;
	for (int i = 0; i < kstr; i++)
	{
		char* r = strstr(BD[i].Otshestvo, key);//vhodit li key v BD[i].Otshestvo
		if (r != nullptr)//da
		{
			cout << BD[i].Familia << " " << BD[i].Imya << " " << BD[i].Otshestvo << " " << BD[i].GodR << " " << BD[i].ID << endl;
			rez = false;
		}
	}
	if (rez == true)//net takih
		//cout << endl << "Zapis' ne naidena!" << endl << endl;
		cout << endl << "Запись не найдена!" << endl << endl;
}

void PoiskZapGR(ZapisBD* BD, int kstr, int k)//poisk zapisi v BD po godu rozhdeniya
{
	bool rez = true;
	for (int i = 0; i < kstr; i++)
	{
		if (BD[i].GodR == k)//da
		{
			cout << BD[i].Familia << " " << BD[i].Imya << " " << BD[i].Otshestvo << " " << BD[i].GodR << " " << BD[i].ID << endl;
			rez = false;
		}
	}
	if (rez == true)//net takih
		//cout << endl << "Zapis' ne naidena!" << endl << endl;
		cout << endl << "Запись не найдена!" << endl << endl;
}

void PoiskZapID(ZapisBD* BD, int kstr, int k)//poisk zapisi v BD po ID
{
	bool rez = true;
	for (int i = 0; i < kstr; i++)
	{
		if (BD[i].ID == k)//da
		{
			cout << BD[i].Familia << " " << BD[i].Imya << " " << BD[i].Otshestvo << " " << BD[i].GodR << " " << BD[i].ID << endl;
			rez = false;
		}
	}
	if (rez == true)//net takih
		//cout << endl << "Zapis' ne naidena!" << endl << endl;
		cout << endl << "Запись не найдена!" << endl << endl;
}

template <typename Tip>
void ObmenZn(Tip &zap1, Tip &zap2)//obmen znachenii peremennyh
{
	Tip per = zap1;
	zap1 = zap2;
	zap2 = per;
}

template <typename Tip>
void Sort(ZapisBD *BD, int kstr, bool(*res)(Tip, Tip))
{
	for (int i = 1; i < kstr; i++)
		for (int j = 0;j < kstr - i; j++)
			if (res(BD[j], BD[j + 1]) == true)//j*j+1
				ObmenZn(BD[j], BD[j + 1]);
}

bool Famb(ZapisBD Zap1, ZapisBD Zap2)
{
	return strcmp(Zap1.Familia, Zap2.Familia) > 0; //1>2
}

bool Famm(ZapisBD Zap1, ZapisBD Zap2)
{
	return strcmp(Zap1.Familia, Zap2.Familia) < 0; //1<2
}

bool Imb(ZapisBD Zap1, ZapisBD Zap2)
{
	return strcmp(Zap1.Imya, Zap2.Imya) > 0;
}

bool Imm(ZapisBD Zap1, ZapisBD Zap2)
{
	return strcmp(Zap1.Imya, Zap2.Imya) < 0;
}

bool Otb(ZapisBD Zap1, ZapisBD Zap2)
{
	return strcmp(Zap1.Otshestvo, Zap2.Otshestvo) > 0;
}

bool Otm(ZapisBD Zap1, ZapisBD Zap2)
{
	return strcmp(Zap1.Otshestvo, Zap2.Otshestvo) < 0;
}

bool GRb(ZapisBD Zap1, ZapisBD Zap2)
{
	if (Zap1.GodR > Zap2.GodR)
		return true;
	else
		return false;
}

bool GRm(ZapisBD Zap1, ZapisBD Zap2)
{
	if (Zap1.GodR < Zap2.GodR)
		return true;
	else
		return false;
}

bool IDb(ZapisBD Zap1, ZapisBD Zap2)
{
	if (Zap1.ID > Zap2.ID)
		return true;
	else
		return false;
}

bool IDm(ZapisBD Zap1, ZapisBD Zap2)
{
	if (Zap1.ID < Zap2.ID)
		return true;
	else
		return false;
}

void PerezapF(fstream &fileBD, char* filename, ZapisBD* BD, int kstr)//perezapis' faila
{
	fileBD.open(filename, ios::out);
	ZapBDVF(fileBD, BD, kstr);
	fileBD.close();
}


int main(int argc, char** argv)
{
	setlocale(LC_ALL, "Russian");

	char* filename = argv[1];//nazvanie faila
	bool cikl = true;//cikl Menu
	int do1 = 0, do2 = 0, do3 = 0, do4 = 0;//vybor deistviya v switch
	char str[255];//stroka BD
	int kstr = 0;//zapisei v BD

	ofstream fileBD(filename, ios::app);//otkrytie ili sozdanie faila
	if (!fileBD.is_open())//ne otkryvaetsya
	{
		Error(filename);
		return 0;
	}
	else
	{
		fileBD.close();//poka zakryt'
		while (cikl = true)
		{
			Menu1();
			cin >> do1;//deistvie v Menu1

			switch (do1)
			{
			case 1:
				break;//zavershit' switch
			case 2:
			{
				fstream fileBD(filename, ios::out);//otkrytie faila na perezapis'
				//cout<< endl << "Vvedite kolichestvo zapisei." << endl << endl;
				cout << endl << "Введите количество записей." << endl << endl;
				cin >> kstr;
				//cout << endl << "Vvedite zapisi cherez Enter." << endl << endl;
				cout << endl << "Введите записи через Enter." << endl << endl;
				cin.ignore();//pervaya stroka bez endl
				ZapVF(fileBD, kstr, str);//zapis' strok s konsoli v fail
				fileBD.close();
				break;//zavershit' switch
			}
			default://inache
				return 0;//zavershit' programmu
			}//zakrytie switch

			fstream fileBD(filename, ios::in);//otkrytie faila na chtenie
			kstr = KolStrok(fileBD);
			ZapisBD* BD = new ZapisBD[kstr];//massiv struktur
			fileBD.seekg(0);//vozvrat v nachalo faila
			for (int i = 0; i < kstr; i++)
			{
				fileBD.getline(str, 255);
				BDf(str, BD, i);//zapolnenie BD
			}
			fileBD.close();

			Menu2();
			cin >> do2;//deistvie v Menu2
			switch (do2)
			{
			case 1:
			{
				PrintBD(BD, kstr);//vyvod na konsol'
				break;
			}
			case 2:
			{
				fileBD.open(filename, ios::app);//otkrytie faila na dozapis'
				//cout << endl << "Vvedite nobuju stroku." << endl << endl;
				cout << endl << "Введите новую строку." << endl << endl;
				ZapVF(fileBD, 2, str);//endl i stroka
				fileBD.close();
				break;//zavershit' switch
			}
			case 3:
			{
				fileBD.open(filename, ios::out);//otkrytie faila na perezapis'
				int keyID = 0;//ID dlya poiska
				//cout << endl << "Vvedite ID nuzhnoi stroki." << endl << endl;
				cout << endl << "Введите ID нужной строки." << endl << endl;
				cin >> keyID;
				UdalZap(fileBD, BD, kstr, keyID);//perezapis' faila bez stroki s keyID
				fileBD.close();
				break;
			}
			case 4:
			{
				do3 = 0;//deistvie v Menu3
				Menu3SP();
				cin >> do3;
				char key[255];//slovo dlya Menu3
				int k = 0;//chislo dlya Menu3
				switch (do3)
				{
				case 1:
				{
					//cout << endl << "Vvedite Familiju." << endl << endl;
					cout << endl << "Введите фамилию." << endl << endl;
					cin >> key;
					PoiskZapF(BD, kstr, key);//poisk po polu Familia
					break;
				}
				case 2:
				{
					//cout << endl << "Vvedite Imya." << endl << endl;
					cout << endl << "Введите имя." << endl << endl;
					cin >> key;
					PoiskZapI(BD, kstr, key);//poisk po polu Imya
					break;
				}
				case 3:
				{
					//cout << endl << "Vvedite Otshestvo." << endl << endl;
					cout << endl << "Введите отчество." << endl << endl;
					cin >> key;
					PoiskZapO(BD, kstr, key);//poisk po polu Otshestvo
					break;
				}
				case 4:
				{
					//cout << endl << "Vvedite god rozhdeniya" << endl << endl;
					cout << endl << "Введите год рождения." << endl << endl;
					cin >> k;
					PoiskZapGR(BD, kstr, k);//poisk po polu GodR
					break;
				}
				case 5:
				{
					//cout << endl << "Vvedite ID" << endl << endl;
					cout << endl << "Введите ID" << endl << endl;
					cin >> k;
					PoiskZapID(BD, kstr, k);//poisk po polu ID
					break;
				}
				case 6:
					break;
				default:
					return 0;
				}
				break;
			}//4
			case 5:
			{
				do3 = 0;//deistvie v Menu3
				Menu3SP();
				cin >> do3;

				switch (do3)
				{
				case 1:
				{
					do4 = 0;//deistvie v Menu4
					Menu4S();
					cin >> do4;
					switch (do4)
					{
					case 1:
					{
						Sort(BD, kstr, Famb);//sortirovka po familii A-Z
						PerezapF(fileBD, filename, BD, kstr);//perezapis' faila
						break;
					}
					case 2:
					{
						Sort(BD, kstr, Famm);//sortirovka po familii Z-A
						PerezapF(fileBD, filename, BD, kstr);//perezapis' faila
						break;
					}
					case 3:
						break;
					default:
						return 0;
					}
					break;
				}
				case 2:
				{
					Menu4S();
					cin >> do4;
					switch (do4)
					{
					case 1:
					{
						Sort(BD, kstr, Imb);
						PerezapF(fileBD, filename, BD, kstr);
						break;
					}
					case 2:
					{
						Sort(BD, kstr, Imm);
						PerezapF(fileBD, filename, BD, kstr);
						break;
					}
					case 3:
						break;
					default:
						return 0;
					}
					break;
				}
				case 3:
				{
					Menu4S();
					cin >> do4;
					switch (do4)
					{
					case 1:
					{
						Sort(BD, kstr, Otb);
						PerezapF(fileBD, filename, BD, kstr);
						break;
					}
					case 2:
					{
						Sort(BD, kstr, Otm);
						PerezapF(fileBD, filename, BD, kstr);
						break;
					}
					case 3:
						break;
					default:
						return 0;
					}
					break;
				}
				case 4:
				{
					Menu4S();
					cin >> do4;
					switch (do4)
					{
					case 1:
					{
						Sort(BD, kstr, GRb);
						PerezapF(fileBD, filename, BD, kstr);
						break;
					}
					case 2:
					{
						Sort(BD, kstr, GRm);
						PerezapF(fileBD, filename, BD, kstr);
						break;
					}
					case 3:
						break;
					default:
						return 0;
					}
					break;
				}
				case 5:
				{
					Menu4S();
					cin >> do4;
					switch (do4)
					{
					case 1:
					{
						Sort(BD, kstr, IDb);
						PerezapF(fileBD, filename, BD, kstr);
						break;
					}
					case 2:
					{
						Sort(BD, kstr, IDm);
						PerezapF(fileBD, filename, BD, kstr);
						break;
					}
					case 3:
						break;
					default:
						return 0;
					}
					break;
				}
				case 6:
					break;//vozvrat v Menu1
				default:
					return 0;
				}//do3
			}//5 - sort
			case 6:
				break;//vozvrat v Menu1
			default:
				return 0;
			}//do2
			delete[]BD;//ochistka pamyati
		}//cikl
	}//else
	system("pause");
	return 0;
}
