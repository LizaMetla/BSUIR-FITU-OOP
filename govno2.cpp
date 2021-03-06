// govno2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"

#include<iomanip>


#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Bus {
protected:
	string model;
	int num;

public:
	Bus() {
		this->model = "KAMAZ";
		this->num = 8787;
	};

	Bus(string model = "", int num = 0) {
		this->model = model;
		this->num = num;
	}
	/*void setModel(string model) {
		this->model = model;
	}
	void setNum(int num) {
		this->num = num;
	}*/
	virtual void show() = 0;
	virtual string combine_all_properties() = 0;


	~Bus() {};
};

class SoftBus : public Bus {
	int seats, s_taken;
	string driver;
public:
	SoftBus(const SoftBus &sb) : Bus(model, num) {
		this->seats = sb.seats;
		this->s_taken = sb.s_taken;
		this->driver = sb.driver;
	}
	SoftBus(string driver = "", string model = "", int num = 0, int seats = 0, int s_taken = 0) : Bus(model, num) {
		this->seats = seats;
		this->s_taken = s_taken;
		this->driver = driver;
	}
	/*void setDriver(string driver) {
		this->driver = driver;
	}
	void setSeats(int seats) {
		this->seats = seats;
	}
	void setS_taken(int s_taken) {
		this->s_taken = s_taken;
	}*/
	void show() {
		cout << "Driver " << driver << ", Model S-" << model << ", Nat. number S-" << num << ", All seats " << seats << ", Empty seats " << seats - s_taken << endl;
	}

	string combine_all_properties() {
		string result = "Soft bus: Driver " + driver + ", Model S-" + model + ", Nat. number S-" + to_string(num) + ", All seats " + to_string(seats) + ", Empty seats " + to_string(seats - s_taken);
		return result;
	}
	~SoftBus() {};

};

class HardBus : public Bus {
	int seats, s_taken;
	string driver;
public:
	HardBus(string driver = "" , string model = "", int num = 0, int seats = 0, int s_taken = 0) : Bus(model, num) {
		this->seats = seats;
		this->s_taken = s_taken;
		this->driver = driver;
	}
	/*void setDriver(string driver) {
		this->driver = driver;
	}
	void setSeats(int seats) {
		this->seats = seats;
	}
	void setS_taken(int s_taken) {
		this->s_taken = s_taken;
	}*/
	void show() {
		cout << "Driver " << driver << ", Model H-" << model << ", Nat. number H-" << num << ", All seats " << seats << ", Empty seats " << seats - s_taken << endl;
	}
	string combine_all_properties() {
		string result = "Hard bus: Driver " + driver + ", Model S-" + model + ", Nat. number S-" + to_string(num) + ", All seats " + to_string(seats) + ", Empty seats " + to_string(seats - s_taken);
		return result;
	}
	~HardBus() {};
};

void write_to_file(Bus *bus) {
	string output_r = bus->combine_all_properties();
	ofstream out;          // поток для записи
	out.open("hello.txt", std::ofstream::out| ofstream::trunc); // окрываем файл для записи
	if (out.is_open())
	{
		out << output_r << std::endl;
	}
	out.close();
}

int main()
{
	Bus* arr[3];
	
		
		string drv = "Fedor", mod = "MAZ";
		int num = 1234, sts = 40, stk = 15;

		SoftBus *sbus = new SoftBus(drv, mod, num, sts, stk);// sbus - обьект класса SoftBus
		arr[0] = sbus;

		drv = "Kirill", mod = "Tesla";
		num = 8888, sts = 6, stk = 3;

		HardBus *hbus = new HardBus(drv, mod, num, sts, stk);// hbus - обьект класса HrdBus
		arr[1] = hbus;

		SoftBus *sb;
		sb = sbus;
		arr[2] = sb;

		for (int i = 0; i < 3; i++) {
			arr[i]->show();
			write_to_file(arr[i]);
		}

	
}