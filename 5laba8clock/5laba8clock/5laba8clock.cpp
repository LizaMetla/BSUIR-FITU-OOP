// ConsoleApplication20.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include "pch.h"
#include <iostream>
#include<list>
#include<cassert>
#include<string>
using namespace std;

class Clock {
	int hours;
	int minutes;
	int seconds;
	string name = "Noname";
public:
	Clock(int hours, int minutes, int seconds);         //Constructor;
	void setTime(int hours, int minutes, int seconds);    //Sets time;
	void setHours(int hours);                           //Sets hours;
	void setMinutes(int minutes);                       //Sets minutes;
	void setSeconds(int seconds);                       //Sets seconds;
	int getHours();                                     //Returns hours;
	int getMinutes();                                   //Returns minutes;
	int getSeconds();                                   //Returns seconds;
	list<int> getTime();                                //Returns time;
	virtual string getName() = 0;                       //Returns name;
	virtual void showTime() = 0;                        //Shows time (hours, minutes, seconds + name);
};

//Returns time
list<int> Clock::getTime() {
	return { hours, minutes, seconds };
}

//Returns hours
int Clock::getHours() {
	return hours;
}

//Returns minutes
int Clock::getMinutes() {
	return minutes;
}

//Returns seconds
int Clock::getSeconds() {
	return seconds;
}

//Constructor
Clock::Clock(int hours, int minutes, int seconds) {
	setTime(hours, minutes, seconds);
}

//Sets time (hours, minutes, seconds)
void Clock::setTime(int hours, int minutes, int seconds) {
	setHours(hours);
	setMinutes(minutes);
	setSeconds(seconds);
}

//Sets hours
void Clock::setHours(int hours) {
	assert(hours > 0 && hours < 25);
	this->hours = hours;
}

//Sets minutes
void Clock::setMinutes(int minutes) {
	assert(minutes > 0 && minutes < 60);
	this->minutes = minutes;
}

//Sets seconds
void Clock::setSeconds(int seconds) {
	assert(seconds > -1 && seconds < 60);
	this->seconds = seconds;
}


class MechanicalWatch : public Clock {
	string name = "Mechanical Watch";
public:
	string getName();                                       //Returns name;
	void showTime();                                        //Shows time (hours, minutes, seconds + name);
	MechanicalWatch(int hours, int minutes, int seconds);   //Constructor;
};

//Shows time (hours, minutes, seconds + name)
void MechanicalWatch::showTime() {
	cout << name << " : " << getHours() << ":" << getMinutes() << ":" << getSeconds() << endl;
}

//Returns name
string MechanicalWatch::getName() {
	return name;
}

//Constructor
MechanicalWatch::MechanicalWatch(int hours, int minutes, int seconds) : Clock(hours, minutes, seconds) {}


class ElectronicClock : Clock {
	string name = "Electronic Clock";
public:
	string getName();                                       //Returns name;
	void showTime();                                        //Shows time (hours, minutes, seconds + name);
	ElectronicClock(int hours, int minutes, int seconds);     //Constructor;
};

//Constructor
ElectronicClock::ElectronicClock(int hours, int minutes, int seconds) : Clock(hours, minutes, seconds) {}

//Returns name
string ElectronicClock::getName() {
	return name;
}

//Shows time (hours, minutes, seconds + name)
void ElectronicClock::showTime() {
	cout << name << " : " << getHours() << ":" << getMinutes() << ":" << getSeconds() << endl;
}

int main() {
	ElectronicClock clock(23, 15, 10);
	clock.showTime();
	cout << clock.getName() << endl;

	MechanicalWatch clockk(22, 55, 10);
	clockk.showTime();
	cout << clockk.getName() << endl;
	clockk.showTime();
	return 0;
}