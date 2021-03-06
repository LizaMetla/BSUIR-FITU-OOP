// 6laba1varik.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//1.	Описать базовый класс «Точка» со следующими полями: 
//координаты и цвет. Методы класса – конструктор, получение значения полей, 
//изменение значения полей, отображение координат точки на экране и перемещение точ-ки.
//Описать базовый класс «Отрезок» со следующими полями : координаты и
//цвет.Методы класса – конструктор, получение значения полей, 
//изменение значения полей, отображение координат отрезка на экране и перемещение оtрезка.


#include "pch.h"
#include <iostream>
#include <string>
#include <locale.h>
#include <ctime>
#include <iomanip>
#include<fstream>

using namespace std;

class Point {
protected:
	int x1_p;
	int y1_p;

	string color;
public:
	Point() {
		x1_p = 0;
		y1_p = 0;
		color = "red";
	}
	Point(int x, int y, string color = "red") {
		x1_p = x;
		y1_p = y;
		this->color = color;
	}
	int getX1() {
		return x1_p;
	}
	int getY1() {
		return y1_p;
	}
	string getColor() {
		return color;
	}
	void setX1() {
		cout << "Enter x1: ";
		cin >> x1_p;
	}
	void setY1() {
		cout << "Enter y1: ";
		cin >> y1_p;
	}
	void setX1(int x) {
		x1_p = x;
	}
	void setY1(int y) {
		y1_p = y;
	}
	void setColor() {
		cout << "Enter color: ";
		cin >> color;
	}
	void setColor(string color) {
		this->color = color;
	}
	void printCoord() {
		cout << "Coordinate and color of this point: " << endl;
		cout << "   x : " << x1_p << endl;
		cout << "   y : " << y1_p << endl;
		cout << "   color : " << color << endl;
	}
	void moveDot() {
		cout << "Enter x1: ";
		cin >> x1_p;
		cout << "Enter y1: ";
		cin >> y1_p;
	}

	
};

class Line: public Point
{
protected:
	int x2_p;
	int y2_p;
public:
	Line(int x1, int y1, int x2, int y2, string color = "white"):Point(x1, x2, color) {
		x2_p = x2;
		y2_p = y2;
	}
	Line() {}
	int getX2() {
		return x2_p;
	}
	int getY2() {
		return y2_p;
	}
	void setX2(int x) {
		x2_p = x;
	}
	void setY2(int y) {
		y2_p = y;
	}
	void printCoord() {
		cout << "Coordinate and color of this point: " << endl;
		cout << "   x1 : " << x1_p << endl;
		cout << "   y1 : " << y1_p << endl;
		cout << "   x2 : " << x2_p << endl;
		cout << "   y2 : " << y2_p << endl;
		cout << "   color : " << color << endl;
	}
	void moveDot() {
		Point::moveDot();
		cout << "Enter x2: ";
		cin >> x2_p;
		cout << "Enter y2: ";
		cin >> y2_p;
	}
};
class Square
{

public:
	Line line1;
	Line line2;
	Square(Line line01, Line line02){
		line1 = line01;//обьект линии,который мы передали в конструктор, свойство line01 присвоили 
		line2 = line02;
	}
	void moveDot() {
		
		cout << "Move line1: ";
		line1.moveDot();
		cout << "Move line2: ";
		line2.moveDot();
	}
	void printCoord() {
		cout << "line1 coord: " << endl;
		line1.printCoord();
		cout << "line2 coord: " << endl;
		line2.printCoord();
	}
	~Square();

};

Square ::~Square ()
{
}
int main()
{
	Line line01(1, 2, 3, 4, "white");
	Line line02(6, 7, 8, 9, "white");
	Square sq(line01, line02);
	sq.printCoord();
	sq.moveDot();

	return 0;

}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
