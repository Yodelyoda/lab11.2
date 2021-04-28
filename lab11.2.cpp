#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <algorithm>
#include <Windows.h> // забезпечення відображення кирилиці
using namespace std;
enum Spec { KOMPNAUK, INFORMAT, TRUDOVIK, FIZIK, MATEM };
string specStr[] = { "«Комп’ютерні науки»", "«Інформатика»", "«Математика та економіка»","«Фізика та інформатика»","«Трудове навчання»" };
struct Student
{
	string prizv;
	unsigned kurs;
	unsigned nomer;
	Spec spec;
	int FIZrate;
	int MATrate;
	union
	{
		int PEDArate;
		int PROGrate;
		int CHISLrate;
	};
};
void Create(char* fname);
void Print(char* fname);
int LineSearch(char* fname);
double LineSearch2(char* fname);
int main()
{ // забезпечення відображення кирилиці:
	SetConsoleCP(1251); // встановлення сторінки win-cp1251 в потік вводу
	SetConsoleOutputCP(1251); // встановлення сторінки win-cp1251 в потік виводу
	char fname[100];
	int N;
	int menuItem;
	do {
		cout << endl << endl << endl;
		cout << "Виберіть дію:" << endl << endl;
		cout << " [1] - введення даних з клавіатури" << endl;
		cout << " [2] - завантвження та вивід даних на екран" << endl;
		cout << " [3] - обчислити кількість студентів середній бал яких більший за 4.5" << endl;
		cout << " [4] - Визначити предмет середній бал якого найбільший" << endl;
		cout << " [0] - вихід та завершення роботи програми" << endl << endl;
		cout << "Введіть значення: "; cin >> menuItem;
		cout << endl << endl << endl;
		switch (menuItem)
		{
		case 1:
			cin.get(); // очищуємо буфер клавіатури – щоб не було символу
			cin.sync(); // "кінець рядка", який залишився після вводу числа
			cout << "Введіть назву файлу: "; cin.getline(fname, sizeof(fname));
			Create(fname);
			break;
		case 2:
			cin.get(); // очищуємо буфер клавіатури – щоб не було символу
			cin.sync(); // "кінець рядка", який залишився після вводу числа
			cout << "Введіть назву файлу: "; cin.getline(fname, sizeof(fname));
			Print(fname);
			break;
		case 3:
			cin.get(); // очищуємо буфер клавіатури – щоб не було символу
			cin.sync(); // "кінець рядка", який залишився після вводу числа
			cout << "Введіть назву файлу: "; cin.getline(fname, sizeof(fname));
			cout << "кількість студентів середній бал яких більший за 4.5 = " << LineSearch(fname) << endl;
			break;
		case 4:
			cin.get(); // очищуємо буфер клавіатури – щоб не було символу
			cin.sync(); // "кінець рядка", який залишився після вводу числа
			cout << "Введіть назву файлу: "; cin.getline(fname, sizeof(fname));
			LineSearch2 (fname);
			break;
		case 0:
			break;
		default:
			cout << "Ви ввели помилкове значення! "
				"Слід ввести число - номер вибраного пункту меню" << endl;
		}
	} while (menuItem != 0);
	return 0;
	
}
void Create(char* fname)
{
	ofstream f(fname, ios::binary);
	if (f.fail())
	{
		cout << "Помилка відкриття файлу '" << fname << "'!" << endl;
		return;
	}
	Student student;
	int spec;
	char ch;
	int i = 0;
	do{
		cout << "Студент No " << i + 1 << ":" << endl; i++;
		cout << " прізвище: "; cin >> student.prizv;
		cout << " курс: "; cin >> student.kurs;
		cout << " порядковий номер студента у групі: "; cin >> student.nomer;
		cout << " Спеціальність (0 - Комп’ютерні науки, 1 - Інформатика, 2 - Математика та економіка, 3 - Фізика та інформатика, 4 -Трудове навчання ): ";
		cin >> spec;
		student.spec = (Spec)spec;
		switch (student.spec)
		{
		case KOMPNAUK:
			cout << " Оцінка з фізики : "; cin >> student.FIZrate;
			cout << " Оцінка з математики : "; cin >> student.MATrate;
			cout << " Оцінка з програмування : "; cin >> student.PROGrate;
			break;
		case INFORMAT:
			cout << " Оцінка з фізики : "; cin >> student.FIZrate;
			cout << " Оцінка з математики : "; cin >> student.MATrate;
			cout << " Оцінка з чисельних методів : "; cin >> student.CHISLrate;
			break;
		case TRUDOVIK:
			cout << " Оцінка з фізики : "; cin >> student.FIZrate;
			cout << " Оцінка з математики : "; cin >> student.MATrate;
			cout << " Оцінка з педагогіки : "; cin >> student.PEDArate;
			break;
		case FIZIK:
			cout << " Оцінка з фізики : "; cin >> student.FIZrate;
			cout << " Оцінка з математики : "; cin >> student.MATrate;
			cout << " Оцінка з педагогіки : "; cin >> student.PEDArate;
			break;
		case MATEM:
			cout << " Оцінка з фізики : "; cin >> student.FIZrate;
			cout << " Оцінка з математики : "; cin >> student.MATrate;
			cout << " Оцінка з педагогіки : "; cin >> student.PEDArate;
			break;
		}
		if (!f.write((char*)& student, sizeof(Student))) {
			cerr << "Помилка запису в файл" << endl;
			f.close();
		}
		cout << "Продовжити?(Y/N)";
		cin >> ch;
		cout << endl;
	} while (ch == 'Y' || ch == 'y');
}
void Print(char* fname)
{
	ifstream f(fname, ios::binary);
	if (f.fail())
	{
		cout << "Помилка відкриття файлу '" << fname << "'!" << endl;
		return;
	}
	Student student;
	cout << "====================================================================================================================================================================================================="
		<< endl;
	cout << "| No | Прізвище | Курс | Порядковий номер студента у групі | Спеціальність | Оцінка з фізики | Оцінка з математики | Оцінка з чисельних методів | Оцінка з програмування | Оцінка з педагогіки|"
		<< endl;
	cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"
		<< endl;
	int i = 0;
	while(f.read((char*)& student, sizeof(Student)))
	{
		cout << "| " << setw(4) << right << i + 1 << " "; i++;
		cout << "| " << setw(13) << left << student.prizv
			<< "| " << setw(6) << left << student.kurs
			<< "| " << setw(36) << right << student.nomer
			<< "| " << setw(20) << left << specStr[student.spec]
			<< "| " << setw(11) << right << student.FIZrate
			<< "| " << setw(11) << right << student.MATrate;
		switch (student.spec)
		{
		case KOMPNAUK:
			cout << "| " << setw(11) << right << "|" << " " << setw(8) << right << student.PROGrate << " |" << setw(11) << right << "|" << endl;
			break;
		case INFORMAT:
			cout << "| " << " " << setw(8) << right << student.CHISLrate << "|" << setw(11) << right << "|" << setw(11) << right << "|" << endl;
		case TRUDOVIK:
		case FIZIK:
		case MATEM:
			cout << "| " << setw(11) << right << "|" << setw(11) << right << "|" << " " << setw(8) << right << student.PEDArate << " |" << endl;
			break;
		}
	}
	cout << "====================================================================================================================================================================================================="
		<< endl;
	cout << endl;
}
int LineSearch(char* fname)
{
	ifstream f(fname, ios::binary);
	if (f.fail())
	{
		cout << "Помилка відкриття файлу '" << fname << "'!" << endl;
		return 0;
	}
	Student student;
	cout << "Прізвища студентів, чий середній бал перевищує 4,5:" << endl;
	int k = 0, n = 0;
	while (f.read((char*)& student, sizeof(Student)))
	{
		if (student.spec == KOMPNAUK)
		{
			n++;
			if ((student.FIZrate + student.MATrate + student.PROGrate) / 3.0 > 4.5)
			{
				k++;
				cout << setw(3) << right << k
					<< " " << student.prizv << endl;
			}
		}
		if (student.spec == INFORMAT)
		{
			n++;
			if ((student.FIZrate + student.MATrate + student.CHISLrate) / 3.0 > 4.5)
			{
				k++;
				cout << setw(3) << right << k
					<< " " << student.prizv << endl;
			}
		}
		if (student.spec == TRUDOVIK || student.spec == FIZIK || student.spec == MATEM)
		{
			n++;
			if ((student.FIZrate + student.MATrate + student.PEDArate) / 3.0 > 4.5)
			{
				k++;
				cout << setw(3) << right << k
					<< " " << student.prizv << endl;
			}
		}

	}
	return k;
}
double LineSearch2(char* fname)
{
	ifstream f(fname, ios::binary);
	if (f.fail())
	{
		cout << "Помилка відкриття файлу '" << fname << "'!" << endl;
		return 0;
	}
	Student student;
	char cw;
	double N = 0, r = 0, q = 0, t = 0, a = 0, b = 0, c = 0, d = 0,j = 0;
	while (f.read((char*)& student, sizeof(Student)))
	{
		if (student.spec == KOMPNAUK)
		{
			r++;
			a += student.FIZrate;
			b += student.MATrate;
			c += student.PROGrate;

		}
		if (student.spec == INFORMAT)
		{
			q++;
			a += student.FIZrate;
			b += student.MATrate;
			d += student.CHISLrate;

		}
		if (student.spec == TRUDOVIK || student.spec == FIZIK || student.spec == MATEM)
		{
			t++;
			a += student.FIZrate;
			b += student.MATrate;
			j += student.PEDArate;
		}
	}
	double aq = a / N;
	double bq = b / N;
	double cq = c / r;
	double dq = d / q;
	double jq = j / t;
	double maximum = max(aq, max(bq, max(cq, dq)));
	maximum = max(maximum, jq);
	if (maximum = aq)
	{
		cout << "предмет, середній бал якого найбільший фізика" << endl;
	}
	else if (maximum = bq)
	{
		cout << "предмет, середній бал якого найбільший математика" << endl;
	}
	else if (maximum = cq)
	{
		cout << "предмет, середній бал якого найбільший програмування" << endl;
	}
	else if (maximum = dq)
	{
		cout << "предмет, середній бал якого найбільший інформатика" << endl;
	}
	else
	{
		cout << "предмет, середній бал якого найбільший педагогіка" << endl;
	}
	return maximum;
};