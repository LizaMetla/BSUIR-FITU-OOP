// ConsoleApplication21.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include<list>
#include<sstream>
#include<cassert>
#include<string>
#include <stdexcept>

using namespace std;

template <class T>
class Clock {
	T hours;
	T minutes;
	T seconds;
public:

	void setTime(T hours, T minutes, T seconds);      //Sets time;
	void setHours(T hours);                           //Sets hours;
	void setMinutes(T minutes);                       //Sets minutes;
	void setSeconds(T seconds);                       //Sets seconds;
	T getHours();                                     //Returns hours;
	T getMinutes();                                   //Returns minutes;
	T getSeconds();                                   //Returns seconds;
	T getTime();                                //Returns time;
	void showTime();                                  //Shows time (hours, minutes, seconds + name);
	string isAMOrPM(T a);                             //Returns is the given time "before noon" or " after noon»;
	void operator += (int seconds);
};

template <class T>
void Clock<T>::operator += (int seconds) {
	int i;
	istringstream(this->seconds) >> i;
	this->seconds += seconds % 60;
	minutes += seconds / 60;
}

//Returns is the given time "before noon" or " after noon»
template <class T>
string Clock<T>::isAMOrPM(T a) {
	//cout << typeid(this->hours).name() << endl;
	return (this->hours < a) ? "Before noon" : "After noon";
}

//Shows time
template <class T>
void Clock<T>::showTime() {
	cout << "Time: " << hours << ":" << minutes << ":" << seconds << endl;
}

//Returns time
template <class T>
T Clock<T>::getTime() {
	return  hours + ":" + minutes + ":" + seconds;
}

//Returns hours
template <class T>
T Clock<T>::getHours() {
	return hours;
}

//Returns minutes
template <class T>
T Clock<T>::getMinutes() {
	return minutes;
}

//Returns seconds
template <class T>
T Clock<T>::getSeconds() {
	return seconds;
}

//Sets time (hours, minutes, seconds)
template <class T>
void Clock<T>::setTime(T hours, T minutes, T seconds) {
	setHours(hours);
	setMinutes(minutes);
	setSeconds(seconds);
}

//Sets hours
template <class T>
void Clock<T>::setHours(T hours) {

	this->hours = hours;
}

//Sets minutes
template <class T>
void Clock<T>::setMinutes(T minutes) {

	this->minutes = minutes;
}

//Sets seconds
template <class T>
void Clock<T>::setSeconds(T seconds) {

	this->seconds = seconds;
}


template <class T2>
class Tran           // класс поддержки транзакций
{
	T2* that;        // текущее значение объекта класса Clock
	T2* prev;       // предыдущее значение объекта класса Clock
public:
	Tran() :prev(NULL), that(new T2) {}     // конструктор
	Tran(const Tran & obj) :                      // конструктор копирования
		that(new T2(*(obj.that))), prev(NULL) {}
	~Tran() { delete that;  delete prev; }    // деструктор
	Tran& operator=(const Tran & obj);   // перегрузка операции присваивания 
	void Show(int);        // отображение значений (предыдущего 
								   // и текущего) объекта класса Clock 
	int BeginTrans(string hours, string minutes, string seconds);     // начало транзакции
	void Commit();        // закрепление транзакции
	void DeleteTrans(); // отмена транзакции
	T2* operator->();     // перегрузка операции ->
};
template <class T2>
Tran<T2>& Tran<T2>::operator=(const Tran<T2> & obj)
{
	if (this != &obj)        // проверка на случай  obj=obj
	{
		delete that;         // удаление текущего значения объекта 
		that = new T2(*(obj.that)); // создание и копирование
	}
	return *this;
}
template <class T2>
T2* Tran<T2>::operator->()     // перегрузка операции -> 
{
	return that;
}
template <class T2>
void Tran<T2>::Show(int fl)     // отображение состояние объекта
{
	cout << "состояния объекта ";
	if (!fl) cout << "до начала транзакции " << endl;
	else cout << "после выполнения транзакции " << endl;
	if (prev) cout << "prev = " << prev->getTime() << endl;    // предыдущее
	else cout << "prev = NULL" << endl;
	cout << "that = " << that->getTime() << endl;	             // текущее
}
template <class T2>
int Tran<T2>::BeginTrans(string hours, string minutes, string seconds)  // начало 
{
	delete prev;                // удаление предыдущего значения
	prev = that;                 // текущее становится предыдущим
	that = new T2(*prev); // новое значение текущего значения
	if (!that) return 0; // ошибка (необходимо отменить действие)
	try
	{
		that->setTime(hours, minutes, seconds);               // изменение состояния объекта
		//throw std::invalid_argument("Неправильно задан интервал вемени");
	}
	catch (const std::exception&)
	{
		return 0;
	}

	return 1;                     // успешное окончание транзакции
}
template <class T2>
void Tran<T2>::Commit()  // закрепление 
{
	delete prev;                     // удаление предыдущего значения
	prev = NULL;                   // предыдущего состояния  нет
}
template <class T2>
void Tran<T2>::DeleteTrans()  // отмена
{
	if (prev != NULL)
	{
		delete that;                    // удаление текущего значения
		that = prev;                   // предыдущее становится текущим
		prev = NULL;                // предыдущего состояния  нет
	}
}
int main()
{

	Tran<Clock<string> > tr;
	setlocale(LC_ALL, "Russian");
	tr->setTime("4", "54", "15");             // начальная инициализация объекта
	tr.Show(0);
	if (tr.BeginTrans("1", "34", "15")) // начало транзакции (изменение объекта)
	{
		tr.Show(1);
		tr.Commit();      // закрепление транзакции
	}
	else {
		tr.DeleteTrans();   // отмена транзакции при ошибке       
		tr.Show(0);
	}

	return 0;
}


