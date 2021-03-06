// oop5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include<iostream>
#include<iomanip>
#include<string.h>
using namespace std;
//Создать абстрактный базовый класс «Студент», а также производные классы «Выпускник» и «Старшекурсник». Все классы должны содержать функции получения и изменения всех полей. Написать программу, позволя-ющую получать сведения о студентах.
class Student
{
public:
	std::string fio;
	int age;

	virtual void get_studet() = 0;
	virtual void get_name() = 0;
	virtual void show_student_type() = 0;

};
class Gratuated : public Student
{
private:

	std::string job;
	int salary;
public:
	Gratuated(double w, double h) : width(w), height(h)
	{
	}
	double getSquare() override
	{
		return width * height;
	}
	double getPerimeter() override
	{
		return width * 2 + height * 2;
	}
	void show_student_type()
	{
		std::cout << "Gratuated" << std::endl;
	}
};
class HighStudent : public Student
{
private:
	std::string speciality;
	int course;

public:
	HighStudent(double r) : radius(r)
	{
	}
	double getSquare() override
	{
		return radius * radius * 3.14;
	}
	double getPerimeter() override
	{
		return 2 * 3.14 * radius;
	}
	void show_student_type()
	{
		std::cout << "High Student" << std::endl;
	}
};

int main()
{
	Gratuated grat();
	HighStudent highst();

	//Rectangle rect(30, 50);
	//Circle circle(30);

	//std::cout << "Rectangle square: " << rect.getSquare() << std::endl;
	//std::cout << "Circle square: " << circle.getSquare() << std::endl;

	std::cout << "Gratuated student: " << grat.getSquare() << std::endl;
	std::cout << "High course student: " << highst.getSquare() << std::endl;

	return 0;
}
