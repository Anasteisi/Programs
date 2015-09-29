#include <iostream>
#include "cmath"
using namespace std;

int main()
{
	setlocale(LC_ALL, "RUS");
	int time1[3], time2[3] = { 0 }; //массивы для моментов времени

	cout << "Время 1: " << endl;
	for (int i = 0; i < 3; i++)
		cin >> time1[i];

	if ((time1[0] > 23) || (time1[1] > 59) || (time1[2] > 59)) //23:59:59 -- максимум
		cout << "Недопустимое значение!" << endl; 

	else
	{
		cout << "Время 2: " << endl;
		for (int i = 0; i < 3; i++)
			cin >> time2[i];

		if ((time2[0] > 23) || (time2[1] > 59) || (time2[2] > 59))
			cout << "Недопустимое значение!" << endl;

		else
		{
			int a = (time1[0]) * 3600 + (time1[1]) * 60 + (time1[2]);
			int b = (time2[0]) * 3600 + (time2[1]) * 60 + (time2[2]); //перевод в секунды для вычисления разности

			int sum = abs(b - a); //модуль разности

			int time3[3] = { 0 };

			time3[0] = sum / 60 / 60; //часы
			sum = sum - time3[0] * 60 * 60; //всего минус целых часов

			time3[1] = sum / 60; //минуты
			sum = sum - time3[1] * 60; //всего минус целых минут

			time3[2] = sum; // остаток -- секунды

			cout << "Разница: " << (time3[0]) << " часов, " << (time3[1]) << " минут, " << (time3[2]) << " секунд." << endl;
		}
	}
		system("pause");
		return 0;
	
}