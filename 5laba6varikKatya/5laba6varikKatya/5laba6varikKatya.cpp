// 5laba6varikKatya.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"

#include <iostream>
using namespace std;

class Bank
{
public:
	int account, balance;
	Bank(int a, int b)
	{
		this->account = a;
		this->balance = b;
	}
};

class Product
{
public:
	char name[21], producer[21];
	int price;
	virtual void Buy(Bank* x) = 0;
};

class Food : public Product
{
public:
	int weight;
	Food(int price)
	{
		this->price = price;
	}
	void Buy(Bank* x) override
	{
		cout << "Пожалуйста, введите вес:" << endl;
		cin >> this->weight;
		x->balance -= this->price*this->weight;
		cout << "Покупка совершена успешно! Остаток на счёте: " << x->balance << "$" << endl;
	}
};

class Films : public Product
{
public:
	int rating;
	Films(int price, int r)
	{
		this->price = price;
		this->rating = r;
	}
	void Buy(Bank* x) override
	{
		int a;
		cout << "Пожалуйста, введите свой возраст:" << endl;
		cin >> a;
		if (a < this->rating)
		{
			cout << "Очень жаль, но ваш возраст не соответствует возрастному ограничению!" << endl;
		}
		else
		{
			x->balance -= this->price;
			cout << "Покупка совершена успешно! Остаток на счёте: " << x->balance << "$" << endl;
		}
	}
};

class Alcohol : public Product
{
public:
	Alcohol(int price)
	{
		this->price = price;
	}
	void Buy(Bank* x) override
	{
		int a;
		cout << "Пожалуйста, введите свой возраст:" << endl;
		cin >> a;
		if (a < 18)
		{
			cout << "Очень жаль, но ваш возраст не соответствует возрастному ограничению!" << endl;
		}
		else
		{
			x->balance -= this->price;
			cout << "Покупка совершена успешно! Остаток на счёте: " << x->balance << "$" << endl;
		}
	}
};

class Discount : public Product
{
public:
	double dis;
	Discount(int price, double d)
	{
		this->price = price;
		this->dis = d;
	}
	void Buy(Bank* x) override
	{
		x->balance -= this->price*this->dis;
		cout << "Покупка совершена успешно! Остаток на счёте: " << x->balance << "$" << endl;
	}
};


int main()
{
	setlocale(LC_ALL, "rus");

	Food apple(5), potato(3), sweet(7);
	Films frozen(10, 6), it(12, 16), dead_pool(11, 18);
	Alcohol finland(7), wine(10), champagne(8);
	Discount tomato(5, 0.7), napkins(3, 0.4);
	Bank client(111, 100);

	cout << "Добро пожаловать в наш виртуальный магазин!" << endl;

	while (true)
	{
		int c, d;
		cout << endl << "Выберите категорию:" << endl
			<< "1. Еда" << endl
			<< "2. Фильмы" << endl
			<< "3. Алкоголь" << endl
			<< "4. Товары по акции" << endl
			<< "0. Выход" << endl;
		cin >> c;
		switch (c)
		{
		case 1:
			cout << endl << "1. Яблоки 5$" << endl
				<< "2. Картошка 3$" << endl
				<< "3. Конфеты 7$" << endl;
			cin >> d;
			switch (d)
			{
			case 1:
				apple.Buy(&client);
				break;
			case 2:
				potato.Buy(&client);
				break;
			case 3:
				sweet.Buy(&client);
				break;
			}
			break;

		case 2:
			cout << endl << "1. Холодное сердце 10$" << endl
				<< "2. Оно 12$" << endl
				<< "3. Дэдпул 11$" << endl;
			cin >> d;
			switch (d)
			{
			case 1:
				frozen.Buy(&client);
				break;
			case 2:
				it.Buy(&client);
				break;
			case 3:
				dead_pool.Buy(&client);
				break;
			}
			break;

		case 3:
			cout << endl << "1. Вино белое 10$" << endl
				<< "2. Шампанское \"Советское\" 8$" << endl
				<< "3. Водка \"Финляндия\" 7$" << endl;
			cin >> d;
			switch (d)
			{
			case 1:
				wine.Buy(&client);
				break;
			case 2:
				champagne.Buy(&client);
				break;
			case 3:
				finland.Buy(&client);
				break;
			}
			break;

		case 4:
			cout << endl << "1. Помидоры 5$" << endl
				<< "2. Бумажные салфетки 3$" << endl;
			cin >> d;
			switch (d)
			{
			case 1:
				tomato.Buy(&client);
				break;
			case 2:
				napkins.Buy(&client);
				break;
			}
			break;

		default:
			return 0;
		}
	}
}