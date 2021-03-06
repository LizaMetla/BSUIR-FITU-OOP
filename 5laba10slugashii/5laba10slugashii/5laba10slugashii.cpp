#define _CRT_SECURE_NO_WARNINGS
// 5laba10slugashii.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

// Создать абстрактный базовый класс «Служащий»,
// содержащий фамилию и имя служащего.
// Производный класс «Работники с почасовой оплатой» содержит следующие поля : 
// оплата за час и часы, 
// отработанные за неделю.
// Производный класс «Работники со сдельной оплатой» содержит следующие поля : 
// оплата единицы продукции и число единиц продукции за неделю.
// Все классы должны содержать функции получения и изменения всех полей.
// Написать программу, позволяющую полу - чать сведения о служащих.


#include "pch.h"
#include <iostream>
#include <locale.h>
#include <iomanip>
#include <ctype.h>

using namespace std;

bool rightName(char *name, int n)
{
	for (int i = 0; i < n; i++)
	{
		if ((name[i] <= 'z' && name[i] >= 'a') || (name[i] <= 'Z' && name[i] >= 'A') || (name[i] <= 'я' && name[i] >= 'а') || (name[i] <= 'Я' && name[i] >= 'А'));
		else
		{
			cout << "Данное поле может содержать только буквы!" << endl;
			return false;
		}
	}
	return true;
}

class employee
{
protected:
	char *fam;
	char *name;
public:
	employee() {
		fam = new char[100];
		name = new char[100];
		strcpy(fam, "NaN");
		strcpy(name, "NaN");
	}
	employee(char f[], char n[]) {
		fam = new char[strlen(f) + 1];
		strcpy(fam, f);
		fam[strlen(f)] = '\0';
		name = new char[strlen(n) + 1];
		strcpy(name, n);
		name[strlen(n)] = '\0';
	}
	employee(const char f[], const char n[]) {
		fam = new char[strlen(f) + 1];
		strcpy(fam, f);
		fam[strlen(f)] = '\0';
		name = new char[strlen(n) + 1];
		strcpy(name, n);
		name[strlen(n)] = '\0';
	}
	~employee() {
		delete[] fam;
		delete[] name;
	}
	virtual void show_info() = 0;
	virtual void get_info() {
		do {
			cout << "Введите фамилию: "; cin >> fam;
		} while (!(rightName(fam, strlen(fam))));
		do {
			cout << "Введите имя: "; cin >> name;
		} while (!(rightName(name, strlen(name))));
	}
};

class hourly_workers : public employee
{
	float payment;
	int hours_week;
public:
	hourly_workers() : employee() {
		payment = 0;
		hours_week = 0;
	}
	hourly_workers(char f[], char n[], float paym, int hours) : employee(f, n) {
		payment = paym;
		hours_week = hours;
	}
	hourly_workers(const char f[], const char n[], float paym, int hours) : employee(f, n) {
		payment = paym;
		hours_week = hours;
	}
	void show_info()
	{
		cout << fam << ' ' << name << endl;
		cout << "Работник почасовой оплаты" << endl;
		cout << "Оплата за 1 час: " << payment << endl;
		cout << "Количество отработанных часов за неделю: " << hours_week << endl;
	}
	void get_info() {
		employee::get_info();
		char str[100];
		do {
			cout << "Введите почасовую оплату: ";
			cin >> str;
			payment = atoi(str);
		} while (!(str[0] >= '1' && str[0] <= '9'));
		do {
			cout << "Количество отработанных за неделю часов: ";
			cin >> str;
			hours_week = atoi(str);
		} while (!(str[0] >= '1' && str[0] <= '9'));
	}
};

class piecework_workers : public employee
{
	float payment_per_unit;
	int units_by_week;
public:
	piecework_workers() : employee() {
		payment_per_unit = 0;
		units_by_week = 0;
	}
	piecework_workers(char f[], char n[], float paym, int hours) : employee(f, n) {
		payment_per_unit = paym;
		units_by_week = hours;
	}
	piecework_workers(const char f[], const char n[], float paym, int hours) : employee(f, n) {
		payment_per_unit = paym;
		units_by_week = hours;
	}
	void show_info()
	{
		cout << fam << ' ' << name << endl;
		cout << "Работник поштучной оплаты" << endl;
		cout << "Оплата за единицу продукции: " << payment_per_unit << endl;
		cout << "Количество единиц продукции: " << units_by_week << endl;
	}
	void get_info() {
		employee::get_info();
		char str[100];
		do {
			cout << "Введите оплату за единицу: ";
			cin >> str;
			payment_per_unit = atoi(str);
		} while (!(str[0] >= '1' && str[0] <= '9'));
		do {
			cout << "Количество единиц продукции: ";
			cin >> str;
			units_by_week = atoi(str);
		} while (!(str[0] >= '1' && str[0] <= '9'));
	}
};


int main()
{
	setlocale(LC_ALL, "rus");
	system("chcp 1251");
	system("cls");
	employee *person[4];
	hourly_workers h1;
	hourly_workers h2("Петров", "Алексей", 7, 4);
	piecework_workers p1;
	piecework_workers p2("Сергеев", "Николай", 4, 5);
	person[0] = &h1;
	cout << endl << "Введите информацию о работнике с почасовой оплатой:" << endl;
	person[0]->get_info();
	person[1] = &h2;
	person[2] = &p1;
	cout << endl << "Введите информацию о работнике с поштучной оплатой:" << endl;
	person[2]->get_info();
	person[3] = &p2;
	cout << endl << setfill('#') << setw(50) << '#' << endl << endl;
	for (int i = 0; i < 4; i++)
	{
		person[i]->show_info();
		cout << endl;
	}
	cout << endl << setfill('#') << setw(50) << '#' << endl << endl;
	system("pause");
	return 0;
}