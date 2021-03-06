// 6laba10bank.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <locale.h>
#include <locale.h>
using namespace std;

class Town
{
protected:
	char nameTown[50];
public:
	Town() {}
	Town(char *nam) {
		strcpy(nameTown, nam);
	}
	Town(const char *nam) {
		strcpy(nameTown, nam);
	}
	void show()
	{
		cout << "\tГород - " << nameTown << endl;
	}
	~Town() {}
};

struct Product {
	char *name;
	float price;
	unsigned amount;
	int numb;
	Product *next;
};


class Shop : virtual public Town
{
protected:
	Product *products;
	unsigned amount;
public:
	static int numberSt;
	void push(const char *nam, float pr, unsigned am) {
		Product *temp = new Product[1];
		temp->name = new char[strlen(nam) + 1];
		strcpy(temp->name, nam);
		temp->price = pr;
		temp->amount = am;
		temp->numb = ++numberSt;
		temp->next = NULL;
		if (products == NULL)
			products = temp;
		else {
			Product *t = products;
			while (t->next != NULL)
			{
				t = t->next;
			}
			t->next = temp;
		}
	}
	Shop() : Town() { products = NULL; }
	Shop(Town& t, const char *nam, float pr, unsigned am) : Town(t) {
		products = NULL;
		push(nam, pr, am);
	}
	void showShop()
	{
		cout << "> Информация о товарах магазина" << endl;
		Town::show();
		Product *temp = products;
		while (temp != NULL)
		{
			cout << '\t' << temp->numb << " | " << temp->name << " | " << temp->price << " у.е. | Кол-во: " << temp->amount << endl;
			temp = temp->next;
		}
	}
	void show()
	{
		cout << "> Информация о товарах магазина" << endl;
		Product *temp = products;
		while (temp != NULL)
		{
			cout << '\t' << temp->name << " | " << temp->price << " у.е. | Кол-во: " << temp->amount << endl;
			temp = temp->next;
		}
	}
	~Shop() {
		while (products != NULL)
		{
			Product *temp = products;
			products = products->next;
			temp->name = new char;
			delete[] temp->name;
		}
	}
};

int Shop::numberSt = 0;

class Bank : virtual public Town
{
protected:
	unsigned account;
	double accAmount;
public:
	Bank() : Town() {}
	Bank(Town& t, unsigned acc, double am) : Town(t), account(acc), accAmount(am) {}
	void showBank() {
		cout << "> Информация о банковском счете" << endl;
		Town::show();
		cout << "\tСчет №" << account << ": " << accAmount << " у.е." << endl;
	}
	void show() {
		cout << "> Информация о банковском счете" << endl;
		cout << "\tСчет №" << account << ": " << accAmount << " у.е." << endl;
	}
	void popolnenie_sheta(float sum)
	{
		accAmount += sum;
	}
	~Bank() {}
};

class Buyer : public Bank, public Shop
{
	float sumPokypki;
public:
	Buyer() : Bank(), Shop(),
		Town() {}
	Buyer(float sumPokyp, Bank& b, Shop& sh, Town& t) : sumPokypki(sumPokyp), Bank(b), Shop(sh), Town(t) {}
	~Buyer() {}
	void show()
	{
		cout << endl << endl << "> Информация о покупке" << endl;
		Shop::show();
		Bank::show();
		cout << "\tСумма покупки: " << sumPokypki << " у.е." << endl;
	}
	int pokupka(int number)
	{
		char flag = 1;
		Product *temp = products;
		while (temp != NULL)
		{
			if (number != temp->numb) temp = temp->next;
			else {
				flag = 0;
				break;
			}
		}
		if (flag) {
			cout << "Такого товара нет в продаже данного магазина" << endl;
			cout << endl;
			return 0;
		}
		if (temp->amount < 1)
		{
			cout << "Данного товара нет в наличии" << endl;
			cout << endl;
			return 0;
		}
		if (temp->price - 0.0000001 >= sumPokypki)
		{
			cout << "Недостаточно средств" << endl;
			cout << endl;
			return 0;
		}
		if (temp->price - 0.0000001 <= accAmount)
		{
			cout << "Покупатель приобрел " << temp->name << endl;
			accAmount -= temp->price;
			temp->amount--;
		}
		else cout << "На счету банка недостаточно средств" << endl;
		cout << endl;
	}
};


int main()
{
	setlocale(LC_ALL, "rus");
	system("chcp 1251");
	system("cls");
	Town t1("Минск");
	t1.show();
	cout << endl;
	cout << "> Создание магазина:" << endl;
	char namePr[40];
	float price;
	int amount;
	cout << "Введите название товара: ";
	cin >> namePr;
	cout << "Цена: ";
	do {
		cin.clear();
		cin.ignore();
		cin >> price;
	} while (price < 1);
	cout << "Количество: ";
	do {
		cin.clear();
		cin.ignore();
		cin >> amount;
	} while (amount < 1);
	Shop s1(t1, namePr, price, amount);
	char choice;
	cout << "Добавить еще продукт? (y - yes)";
	cin >> choice;
	while (choice == 'y')
	{
		cout << "Введите название товара: ";
		cin >> namePr;
		cout << "Цена: ";
		do {
			cin >> price;
			cin.ignore();
			cin.clear();
		} while (price < 1);
		cout << "Количество: ";
		do {
			cin >> amount;
			cin.ignore();
			cin.clear();
		} while (amount < 1);
		s1.push(namePr, price, amount);
		cout << "Добавить еще продукт? (y - yes)";
		cin >> choice;
	}
	s1.showShop();
	cout << endl;
	long acc;
	double money;
	cout << "> Создание банковского счета:" << endl;
	cout << "Укажите номер счета (0 - 10.000.000): ";
	do {
		cin >> acc;
	} while (acc < 0 || acc > 10000000);
	cout << "Количество средств на счету: ";
	cin >> money;
	cout << endl;
	Bank b1(t1, acc, money);
	b1.showBank();
	cout << endl;
	double sum;
	int number;
	cout << "Введите сумму покупки: ";
	do {
		cin >> sum;
	} while (sum > money + 0.0000001);
	Buyer br1(sum, b1, s1, t1);
	cout << "\n\nУкажите номер желаемого товара: " << endl << endl;
	do {
		s1.showShop();
		cin >> number;
		br1.pokupka(number);
		cout << "Желаете что-нибудь еще? (y - yes) ";
		cin >> choice;
	} while (choice == 'y');
	br1.show();
	cout << endl;
	system("pause");
}