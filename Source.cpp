#include <iostream>
#include <string>
#include <cmath>
#include <Windows.h>

using namespace std;

struct Element
{
	string FIO = "";
	string data;
	string adress;
};

Element* Mas;

int N = 0;

int Hash(int sum, int HashTable); // ���������� �����
int Sum(string str); // ����� ��������� ��� ��� ������� �����

void CinHash(int i); // ���� ������ ��������
void CinHashK(int i); // ���� ���������� ���������

void CoutHash(int i); // ����� ��� �������
void Chek(int i);

void Menu(); // ����

int main()
{
	setlocale(0, "RUS");
	SetConsoleCP(1251);
	bool F = 1;
	int i;
	int n;
	cout << "������� ������� ��������� ����� �������� � ��� �������" << endl;
	cin >> i;
	Mas = new Element[i];
	while (F)
	{

		Menu();
		cout << "" << endl;
		cin >> n;
		system("cls");
		switch (n)
		{
		case 1:
		{
			CinHash(i);
			break;
		}
		case 2:
		{
			CinHashK(i);
			break;
		}
		case 3:
		{
			CoutHash(i);
			break;
		}
		case 4:
		{
			Chek(i);
			break;
		}
		case 5:
		{
			F = 0;
			break;
		}
		default:
			cout << "������� ����� �������� ������� ���� � ����" << endl;
		}
	}
	delete[] Mas;
}

void Menu()
{
	cout << "\t����" << endl;
	cout << "1) ������ 1 ������� � �������" << endl;
	cout << "2) ������ ��������� ��������� � �������" << endl;
	cout << "3) ������� ������� �� �����" << endl;
	cout << "4) ����� �������� �� �����" << endl;
	cout << "5) ���������� ������ � ��������" << endl;
}

void CinHash(int i)
{
	bool f = 1;
	int k;
	Element element;
	cout << "������� ������ ���������" << endl;
	cout << "������� ���" << endl;
	getline(cin >> ws, element.FIO);
	cout << "������� ���� ��������" << endl;
	getline(cin >> ws, element.data);
	cout << "������� ������ ����������" << endl;
	getline(cin >> ws, element.adress);
	int sum = Sum(element.FIO);
	int key = Hash(sum, i);
	if (Mas[key].FIO == "")
	{
		Mas[key] = element;
	}
	else
	{
		k = key + 1;
		while ((k < i) && f)
		{
			if (Mas[k].FIO == "")
			{
				Mas[k] = element;
				f = 0;
			}
			else
			{
				k++;
			}
		}
		if (f)
		{
			k = 0;
			while ((k < key) && f)
			{
				if (Mas[k].FIO == "")
				{
					Mas[k] = element;
					f = 0;
				}
				else
				{
					k++;
				}
			}
		}
		f = 1;
	}
}
void CinHashK(int i)
{
	int n;
	bool f = 1;
	int k;
	Element element;
	cout << "������� ���������� �������� ���������" << endl;
	cin >> n;
	while (n > 0)
	{
		cout << "������� ������ ���������" << endl;
		cout << "������� ���" << endl;
		getline(cin >> ws, element.FIO);
		cout << "������� ���� ��������" << endl;
		getline(cin >> ws, element.data);
		cout << "������� ������ ����������" << endl;
		getline(cin >> ws, element.adress);
		int sum = Sum(element.FIO);
		int key = Hash(sum, i);
		if (Mas[key].FIO == "")
		{
			Mas[key] = element;
		}
		else
		{
			k = key + 1;
			while ((k < i) && f)
			{
				if (Mas[k].FIO != "")
				{
					Mas[k] = element;
					f = 0;
				}
				else
				{
					k++;
				}
			}
			if (f)
			{
				k = 0;
				while ((k < key) && f)
				{
					if (Mas[k].FIO != "")
					{
						Mas[k] = element;
						f = 0;
					}
					else
					{
						k++;
					}
				}
			}
			f = 1;
		}
		n--;
	}
}

void Chek(int i)
{
	bool f = 1;
	string a;
	cout << "������� ���� ���:" << endl;
	getline(cin >> ws, a);
	int sum = Sum(a);
	int key = Hash(sum, i);
	if (Mas[key].FIO == a)
	{
		cout << Mas[key].FIO << endl;
		cout << Mas[key].data << endl;
		cout << Mas[key].adress << endl;
	}
	else
	{
		int k = key + 1;
		while ((k < i) && (f))
		{
			if (Mas[k].FIO == a)
			{
				f = 0;
				cout << Mas[k].FIO << endl;
				cout << Mas[k].data << endl;
				cout << Mas[k].adress << endl;
			}
			k++;
		}
		if (f)
		{
			k = 0;
			while ((k < key) && (f))
			{
				if (Mas[k].FIO == a)
				{
					f = 0;
					cout << Mas[k].FIO << endl;
					cout << Mas[k].data << endl;
					cout << Mas[k].adress << endl;
				}
				k++;
			}
		}
		if (f)
		{
			cout << "�������� �������� ��� � ������� ��� ���� ����� �������" << endl;
		}
	}
}

void CoutHash(int i)
{
	int k = 0;
	int m = 1;
	while (i > 0)
	{
		if (Mas[k].FIO != "")
		{
			cout << m << ") " << Mas[k].FIO << endl;
			cout << "   " << Mas[k].data << endl;
			cout << "   " << Mas[k].adress << endl;
			m++;
		}
		k++;
		i--;
	}
}

int Sum(string str)
{
	int sum = 0;
	for (int k = 0; k < str.size(); k++)
	{
		sum = sum + (int)str[k];
	}
	sum = abs(sum);
	return sum;
}

int Hash(int sum, int HashTable)
{
	int Key = sum % HashTable;
	return Key;
}