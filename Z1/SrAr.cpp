#include <ctime>
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	setlocale(LC_ALL, "RUS");
	srand(time(NULL));

	{int n;
	cout << "������� ���������� ���������:" << endl;
	cin >> n;//kolichextvo elementov v massive
	int *x = new int[n];//massiv
	double sum = 0;//summa elementov
	for (int i = 0; i < n; ++i)
	{
		x[i] = rand() % 24;//[0;23]
		cout << x[i] << endl;
		sum = sum + x[i];
	}
	cout << "������� ��������������:" << sum / n << endl;
	delete[]x;}

	{int n;
	cout << "������� ���������� ���������:" << endl;
	cin >> n;//kolichextvo elementov v massive
	int *x = new int[n];//massiv
	double sum = 0;//summa elementov
	for (int i = 0; i < n; ++i)
	{
		x[i] = 50 + rand() % 10;//[50;59]
		cout << x[i] << endl;
		sum = sum + x[i];
	}
	cout << "������� ��������������:" << sum / n << endl;
	delete[]x;}

	{int n;
	cout << "������� ���������� ���������:" << endl;
	cin >> n;//kolichextvo elementov v massive
	int *x = new int[n];//massiv
	double sum = 0;//summa elementov
	for (int i = 0; i < n; ++i)
	{
		x[i] = rand() % 13 - 5;//[-7;5]
		cout << x[i] << endl;
		sum = sum + x[i];
	}
	cout << "������� ��������������:" << sum / n << endl;
	delete[]x;}

	system("pause");
	return 0;
}