// 7laba1varik.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <iostream>

using namespace std;

template <class T1, class T2>

T1 max(T1 x, T2 y)

{

	cout << "Вызвана шаблонная функция. " << endl;

	if (x == y)

	{

		return -1;

	}

	else if (x > y)

		return x;

	else

		return y;

	cout << endl;

}

char* max(char* x, char* y)

{

	char t[] = "";

	cout << "Вызвана специализированная функция. " << endl;

	if (strlen(x) == strlen(y))

	{

		cout << "Одинаковое количество элементов строк в строках " << x << " и " << y;

		return t;

	}

	else if (strlen(x) > strlen(y))

		return x;

	else

		return y;

	cout << endl;

}

int main()

{

	setlocale(LC_ALL, "Rus");

	int a;

	a = max(2, 10);

	if (a == -1)cout << "Элементы равны" << endl;

	else cout << "Большее число " << a;

	cout << endl;

	char str1[] = "mo world";

	char str2[] = "mo world";

	cout << max(str1, str2) << endl;

	system("pause");

	return 0;

}