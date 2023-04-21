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

int Hash(int sum, int HashTable); // нахождение ключа
int Sum(string str); // сумма элементов ФИО для подбора ключа

void CinHash(int i); // Ввод одного элемента
void CinHashK(int i); // Ввод нескольких элементов

void CoutHash(int i); // Вывод ХЭШ таблицы
void Chek(int i);

void Menu(); // Меню

int main()
{
	setlocale(0, "RUS");
	SetConsoleCP(1251);
	bool F = 1;
	int i;
	int n;
	cout << "Введите сколько элементов может хранится в ХЭШ таблице" << endl;
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
			cout << "Введите номер элемента который есть в меню" << endl;
		}
	}
	delete[] Mas;
}

void Menu()
{
	cout << "\tМеню" << endl;
	cout << "1) Ввести 1 элемент в таблицу" << endl;
	cout << "2) Ввести несколько элементов в таблицу" << endl;
	cout << "3) Вывести таблицу на экран" << endl;
	cout << "4) Поиск элемента по ключу" << endl;
	cout << "5) Законьчить работу с таблицей" << endl;
}

void CinHash(int i)
{
	bool f = 1;
	int k;
	Element element;
	cout << "Ввидите данные элементов" << endl;
	cout << "Введите ФИО" << endl;
	getline(cin >> ws, element.FIO);
	cout << "Введите дату рождения" << endl;
	getline(cin >> ws, element.data);
	cout << "Введите адресс проживания" << endl;
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
	cout << "Введите количество вводимых элементов" << endl;
	cin >> n;
	while (n > 0)
	{
		cout << "Ввидите данные элементов" << endl;
		cout << "Введите ФИО" << endl;
		getline(cin >> ws, element.FIO);
		cout << "Введите дату рождения" << endl;
		getline(cin >> ws, element.data);
		cout << "Введите адресс проживания" << endl;
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
	cout << "Введите ключ ФИО:" << endl;
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
			cout << "Искомого элемента нет в таблице или ключ введён неверно" << endl;
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