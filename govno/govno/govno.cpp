#define _CRT_SECURE_NO_WARNINGS

#include "pch.h"
#include <iostream>
#include <string>
#include <locale.h>
#include <ctime>
#include <iomanip>
#include<fstream>

using namespace std;

int** create_mas() {
	cout << "Введите размерность матрицы: ";
	int n;
	cin >> n;
	srand(time(0));
	int **array = new int*[n];
	for(int i = 0; i < n; i++)
		array[i] = new int[n];
	for (int row_i = 0; row_i < n; row_i++)
		for (int column_i = 0; column_i < n; column_i++)
			array[row_i][column_i] = (rand() % 10 + 1);
	return array;

}


class MatrixSettings {
	int **mas;

public:
	MatrixSettings() {
		mas = create_mas();
	}

	MatrixSettings(int **array)//конструктор с параметрами
	{
		mas = array;
	}
	MatrixSettings(const MatrixSettings &ms) {
		mas = ms.mas;
	}
	void save_in_file() {
		string result = "";
		ofstream out;
		out.open("savings_in_file.txt", std::ofstream::out | ofstream::trunc);

		for (int i = 0; i < sizeof(mas); i++) {
			for (int j = 0; j < sizeof(mas); j++) {
				result += to_string(mas[i][j]) + " ";

			}
			result += "\n";
		}
		out << result;
		out.close();
	}
	void part1() {
		int min = mas[0][0];
		int min_index_i = 0;
		int min_index_j = 0;

		for (int i = 0; i < sizeof(mas); i++)
			for (int j = 1; j < sizeof(mas); j++)
				if (min > mas[i][j])
				{
					min = mas[i][j];
					min_index_i = i;
					min_index_j = j;
				}
		o_matrix(min_index_i, min_index_j);
		cout << min_index_i << endl;
		cout << min_index_j << endl;
	}
	void print_matrix() {
		for (int i = 0; i < sizeof(mas); i++) {
			for (int j = 0; j < sizeof(mas); j++)
				cout << mas[i][j] << " ";
			cout << endl;
		}
		cout << endl;
	}
	void o_matrix(int i_min,int j_min) 
	{
		for (int j = 0; j < sizeof(mas); j++)
			mas[i_min][j] = 0;
		for (int i = 0; i < sizeof(mas); i++)
			mas[i][j_min] = 0;

	}
	void part2() {
		for (int i = 0; i < sizeof(mas); i++)
			for (int j = 0; j < sizeof(mas); j++)
				if (mas[i][j] % 2 != 0) {

					int temp = mas[i][0];
					mas[i][0] = mas[i][j];
					mas[i][j] = temp;
					break;
				}
	}
	 ~MatrixSettings() {
		/*for (int i = 0; i < sizeof(mas); i++)
		{
			delete[] mas[i]; // delete array within matrix
		}
		// delete actual matrix
		delete[] mas;*/
	}

	
};

int main() {
	setlocale(LC_ALL, "Russian");
	int **k = create_mas();
	MatrixSettings ms(k);
	ms.print_matrix();
	ms.part2();
	ms.print_matrix();
	MatrixSettings ms2(ms);
	ms2.print_matrix();
	ms2.part1();
	ms2.print_matrix();
	ms2.save_in_file();
	return 0;
}
