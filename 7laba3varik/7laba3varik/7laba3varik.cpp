#define _CRT_SECURE_NO_WARNINGS
// 7laba3varik.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <stdio.h>
#include "pch.h"
#include <iostream>


using namespace std;

template<class T>
class vector
{
	T* ms;
	int size, i;
public:
	vector();
	void del();
	int col();
	void add();
	int func1();
	void output();
};

template<class T>
inline vector<T>::vector()
{
	cout << "введите размер вектора:";
	size = func1();
	ms = new T[size];
	for (int i = 0; i < size; i++)
	{
		cin >> ms[i];
	}
}
template<class T>
inline void vector<T>::del()
{
	cout << "\nвыберете номер элемента, который хотите удалить:";
	for (i = 0; i < size; i++)
	{
		cout << endl << i + 1 << "." << ms[i] << " " << endl;
	}
	int c;
	while (true)
	{
		c = func1();
		if (c > size)
		{
			cout << "такого элемента нет, повторите попытку:";
		}
		else
			break;
	}
	c--;
	for (c; c < size; c++)
	{
		ms[c] = ms[c + 1];
	}
	size--;
	cout << "результат:" << endl;
	output();
};
template<class T>
inline int vector<T>::col()
{
	T *ms1;
	T k = 0;
	cout << "\nвведите размер второго вектора:";
	int size1 = func1();
	if (size1 != size)
	{
		cout << "векторы находятся в разных пространствах\n";
		return 0;
	}
	ms1 = new T[size1];
	cout << "введите элементы второго массива\n";
	for (int i = 0; i < size1; i++)
	{
		cin >> ms1[i];
	}
	k = ms[0] / ms1[0];
	for (i = 1; i < size; i++)
	{
		if (k == (ms[i] / ms1[i]))
		{
			continue;
		}
		else
		{
			cout << "векторы не коллинеарны\n";
			return 0;
		}
	}
	if (i == size)
	{
		cout << "векторы коллинеарны\n";
	}
	return 0;
}
template<class T>
inline void vector<T>::add()
{
	T k;
	T* r;
	r = new T[size];
	for (i = 0; i < size; i++)
	{
		r[i] = ms[i];
	}
	cout << "введите элемент который хотите добавить:";
	cin >> k;
	ms = new T[++size];
	for (i = 0; i < size; i++)
	{
		ms[i] = r[i];
	}
	ms[size - 1] = k;
	cout << "результат:" << endl;
	output();
}
template<class T>
inline int vector<T> ::func1()
{
	char a[15];
	int i, j, k, s, n;
	setlocale(LC_ALL, "rus");
	rewind(stdin);
	fgets(a, 15, stdin);
	s = 1;
	while (s == 1)
	{
		s = 0;
		if ((strlen(a)) > 10)
		{
			s = 1;
			printf("\nнеправильно введены данные, повтрите попытку: ");
			rewind(stdin);
			fgets(a, 15, stdin);
			continue;
		}
		for (i = 0; i < (strlen(a)); i++)
		{
			if ((a[i] >= 48) && (a[i] <= 57) && (a[i] != ' '))
			{
				continue;
			}
			else
			{
				if (a[i] == '\n')
				{
					break;
				}
				else
				{
					printf("\nнеправильно введены данные, повтрите попытку: ");
					s = 1;
					fgets(a, 15, stdin);
					break;
				}
			}
		}
	}
	sscanf(a, "%d", &n);
	return n;
}

template<class T>
void vector<T>::output()
{
	for (i = 0; i < size; i++)
	{
		cout << ms[i] << " ";
	}
	cout << endl;
}

int main()
{
	setlocale(LC_ALL, "rus");
	cout << "целочисленный массив:\n";
	vector<int>a;
	cout << "дробный массив:\n";
	vector<double>b;
	while (true)
	{
		cout << "\nвыберете операцию:\n";
		cout << "1.добавить элемент.\n";
		cout << "2.удалить элемент.\n";
		cout << "3.коллинеарность векторов\n";
		cout << "4.выход.\n";
		switch (a.func1())
		{
		case 1:
			cout << "целочисленный массив:\n";
			a.add();
			cout << "дробный массив:\n";
			b.add();
			break;
		case 2:
			cout << "целочисленный массив:\n";
			a.del();
			cout << "дробный массив:\n";
			b.del();
			break;
		case 3:
			cout << "целочисленный массив:\n";
			a.col();
			cout << "дробный массив:\n";
			b.col();
			break;
		case 4:
			return 0;
		default:
			cout << "такого номера нет, повторите попытку:";
			break;
		}

	}
}