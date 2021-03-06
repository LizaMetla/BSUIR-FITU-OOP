
#include "pch.h"
#include <iostream>
#include<list>
#include<sstream>
#include<cassert>
#include<string>
using namespace std;

//parametr shablona class, can take any of data types
template <class T>
class Clock {
	T hours;
	T minutes;
	T seconds;
public:
	Clock(T hours, T minutes, T seconds);             //Constructor;
	void setTime(T hours, T minutes, T seconds);      //Sets time;
	void setHours(T hours);                           //Sets hours;
	void setMinutes(T minutes);                       //Sets minutes;
	void setSeconds(T seconds);                       //Sets seconds;
	T getHours();                                     //Returns hours;
	T getMinutes();                                   //Returns minutes;
	T getSeconds();                                   //Returns seconds;
	list<T> getTime();                                //Returns time;
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

/*
//Returns is the given time "before noon" or " after noon»
template <class T>
string Clock<T>::isAMOrPM() {
	int i;
	istringstream ( hours ) >> i;
	return (i < 12) ? "Before noon" : "After noon";
}*/

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
list<T> Clock<T>::getTime() {
	return { hours, minutes, seconds };
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

//Constructor
template <class T>
Clock<T>::Clock(T hours, T minutes, T seconds) {
	setTime(hours, minutes, seconds);
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
	//assert (int(hours) > 0 && int(hours) < 25);
	this->hours = hours;
}

//Sets minutes
template <class T>
void Clock<T>::setMinutes(T minutes) {
	//assert (int(minutes) > 0 && int(minutes) < 60);
	this->minutes = minutes;
}

//Sets seconds
template <class T>
void Clock<T>::setSeconds(T seconds) {
	//assert (int(seconds) > -1 && int(seconds) < 60);
	this->seconds = seconds;
}


int main() {
	list<string> lst = { "1", "34", "15" };
	Clock<string> clock1("1", "34", "15");
	clock1.showTime();
	cout << clock1.isAMOrPM("12") << endl;
	clock1.setHours("20");
	clock1.showTime();
	cout << clock1.isAMOrPM("12") << endl << endl;

	Clock<int> clock2(1, 34, 15);
	clock2.showTime();
	cout << clock2.isAMOrPM(12) << endl;
	clock2.setHours(20);
	clock2.showTime();
	cout << clock2.isAMOrPM(12) << endl;

	clock2 += 75;
	clock2.showTime();
	return 0;
}