#define _CRT_SECURE_NO_WARNING

#include <stdio.h>
#include "pch.h"
#include <iostream>

#include <string>
#include <locale.h>
#include <iomanip>

using namespace std;

class Motor {
private:
	int value;

public:
	int get_value(){return value; }
	//constructor
	Motor(int i) { 
		value = i;
	    cout << "Инициализация класса Motor " << endl;}
	//destructor
	~Motor() {
		cout << " Деструктор класса Motor" << endl;
	}
};

class Body {
private:
	string type ;
	
public:
	
	string get_type() { return type; }
	//constructor
	Body(string ttype) {
		type = ttype; 
		cout << "Инициализация класса Body " << endl;
	}
	//destructor
	~Body() {
		cout << " Деструктор класса Body" << endl;
	}
};

class Color {
private:
	string color;

public:
	
	string get_color() { return color; }
	//constructor
	Color(string ccolor) { 
		color = ccolor;
		cout << "Инициализация класса Color " << endl;
	}

	//destructor
	~Color() {
		cout << " Деструктор класса Color" << endl;
	}
};

class Car : public Motor, public Body, public Color {
public:
	/* Инициализация Body,Motor,Color через конструктор Car*/
	Car(int value, string type, string color) : Motor(value), Body(type), Color(color)
	{
		cout << "Инициализация класса Car : Mersedess\n";
	}
	string make_car() { return "Объём двигателя: " + to_string(get_value()) + ", Тип кузова: " + get_type() + ", Цвет: " + get_color() + "\n"; }
	~Car() {
		cout << " Деструктор класса Car" << endl;
	}
};
int main()
{
	setlocale(LC_ALL, "Rus");
	Car car(1595, "Crossover", "Black");
	cout << car.make_car();
	return 0;
}