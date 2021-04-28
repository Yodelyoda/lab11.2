#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <algorithm>
#include <Windows.h> // ������������ ����������� ��������
using namespace std;
enum Spec { KOMPNAUK, INFORMAT, TRUDOVIK, FIZIK, MATEM };
string specStr[] = { "���������� �����", "������������", "����������� �� ��������","�Գ���� �� �����������","�������� ���������" };
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
{ // ������������ ����������� ��������:
	SetConsoleCP(1251); // ������������ ������� win-cp1251 � ���� �����
	SetConsoleOutputCP(1251); // ������������ ������� win-cp1251 � ���� ������
	char fname[100];
	int N;
	int menuItem;
	do {
		cout << endl << endl << endl;
		cout << "������� ��:" << endl << endl;
		cout << " [1] - �������� ����� � ���������" << endl;
		cout << " [2] - ������������ �� ���� ����� �� �����" << endl;
		cout << " [3] - ��������� ������� �������� ������� ��� ���� ������ �� 4.5" << endl;
		cout << " [4] - ��������� ������� ������� ��� ����� ���������" << endl;
		cout << " [0] - ����� �� ���������� ������ ��������" << endl << endl;
		cout << "������ ��������: "; cin >> menuItem;
		cout << endl << endl << endl;
		switch (menuItem)
		{
		case 1:
			cin.get(); // ������� ����� ��������� � ��� �� ���� �������
			cin.sync(); // "����� �����", ���� ��������� ���� ����� �����
			cout << "������ ����� �����: "; cin.getline(fname, sizeof(fname));
			Create(fname);
			break;
		case 2:
			cin.get(); // ������� ����� ��������� � ��� �� ���� �������
			cin.sync(); // "����� �����", ���� ��������� ���� ����� �����
			cout << "������ ����� �����: "; cin.getline(fname, sizeof(fname));
			Print(fname);
			break;
		case 3:
			cin.get(); // ������� ����� ��������� � ��� �� ���� �������
			cin.sync(); // "����� �����", ���� ��������� ���� ����� �����
			cout << "������ ����� �����: "; cin.getline(fname, sizeof(fname));
			cout << "������� �������� ������� ��� ���� ������ �� 4.5 = " << LineSearch(fname) << endl;
			break;
		case 4:
			cin.get(); // ������� ����� ��������� � ��� �� ���� �������
			cin.sync(); // "����� �����", ���� ��������� ���� ����� �����
			cout << "������ ����� �����: "; cin.getline(fname, sizeof(fname));
			LineSearch2 (fname);
			break;
		case 0:
			break;
		default:
			cout << "�� ����� ��������� ��������! "
				"��� ������ ����� - ����� ��������� ������ ����" << endl;
		}
	} while (menuItem != 0);
	return 0;
	
}
void Create(char* fname)
{
	ofstream f(fname, ios::binary);
	if (f.fail())
	{
		cout << "������� �������� ����� '" << fname << "'!" << endl;
		return;
	}
	Student student;
	int spec;
	char ch;
	int i = 0;
	do{
		cout << "������� No " << i + 1 << ":" << endl; i++;
		cout << " �������: "; cin >> student.prizv;
		cout << " ����: "; cin >> student.kurs;
		cout << " ���������� ����� �������� � ����: "; cin >> student.nomer;
		cout << " ������������ (0 - ��������� �����, 1 - �����������, 2 - ���������� �� ��������, 3 - Գ���� �� �����������, 4 -������� �������� ): ";
		cin >> spec;
		student.spec = (Spec)spec;
		switch (student.spec)
		{
		case KOMPNAUK:
			cout << " ������ � ������ : "; cin >> student.FIZrate;
			cout << " ������ � ���������� : "; cin >> student.MATrate;
			cout << " ������ � ������������� : "; cin >> student.PROGrate;
			break;
		case INFORMAT:
			cout << " ������ � ������ : "; cin >> student.FIZrate;
			cout << " ������ � ���������� : "; cin >> student.MATrate;
			cout << " ������ � ��������� ������ : "; cin >> student.CHISLrate;
			break;
		case TRUDOVIK:
			cout << " ������ � ������ : "; cin >> student.FIZrate;
			cout << " ������ � ���������� : "; cin >> student.MATrate;
			cout << " ������ � ��������� : "; cin >> student.PEDArate;
			break;
		case FIZIK:
			cout << " ������ � ������ : "; cin >> student.FIZrate;
			cout << " ������ � ���������� : "; cin >> student.MATrate;
			cout << " ������ � ��������� : "; cin >> student.PEDArate;
			break;
		case MATEM:
			cout << " ������ � ������ : "; cin >> student.FIZrate;
			cout << " ������ � ���������� : "; cin >> student.MATrate;
			cout << " ������ � ��������� : "; cin >> student.PEDArate;
			break;
		}
		if (!f.write((char*)& student, sizeof(Student))) {
			cerr << "������� ������ � ����" << endl;
			f.close();
		}
		cout << "����������?(Y/N)";
		cin >> ch;
		cout << endl;
	} while (ch == 'Y' || ch == 'y');
}
void Print(char* fname)
{
	ifstream f(fname, ios::binary);
	if (f.fail())
	{
		cout << "������� �������� ����� '" << fname << "'!" << endl;
		return;
	}
	Student student;
	cout << "====================================================================================================================================================================================================="
		<< endl;
	cout << "| No | ������� | ���� | ���������� ����� �������� � ���� | ������������ | ������ � ������ | ������ � ���������� | ������ � ��������� ������ | ������ � ������������� | ������ � ���������|"
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
		cout << "������� �������� ����� '" << fname << "'!" << endl;
		return 0;
	}
	Student student;
	cout << "������� ��������, ��� ������� ��� �������� 4,5:" << endl;
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
		cout << "������� �������� ����� '" << fname << "'!" << endl;
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
		cout << "�������, ������� ��� ����� ��������� ������" << endl;
	}
	else if (maximum = bq)
	{
		cout << "�������, ������� ��� ����� ��������� ����������" << endl;
	}
	else if (maximum = cq)
	{
		cout << "�������, ������� ��� ����� ��������� �������������" << endl;
	}
	else if (maximum = dq)
	{
		cout << "�������, ������� ��� ����� ��������� �����������" << endl;
	}
	else
	{
		cout << "�������, ������� ��� ����� ��������� ���������" << endl;
	}
	return maximum;
};