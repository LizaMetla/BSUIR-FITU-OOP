// 4laba10matrix.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//10.	Определить базовый класс для работы с матрицами, предусмотрев ввод, вывод матриц и выполнение следующих операций: 

#include "pch.h"
#include <iostream>
#include <iostream>
#include <locale.h>
using namespace std;

class Matrix
{
protected:
	int x;
	int y;
	int **data;
public:
	Matrix() {}
	Matrix(int x2, int y2) : x(x2), y(y2)
	{
		data = new int*[x2];
		for (size_t i = 0; i < x2; i++)
		{
			data[i] = new int[y2];
		}
		for (size_t i = 0; i < x2; i++)
		{
			for (size_t j = 0; j < y2; j++)
			{
				data[i][j] = 0;
			}
		}
	}
	virtual ~Matrix() {}


	virtual void enter()
	{
		for (size_t i = 0; i < x; i++)
		{
			for (size_t j = 0; j < y; j++)
			{
				cout << "Эллемент [" << i << "][" << j << "] = ";
				cin >> data[i][j];
				cin.clear();
				cin.ignore();
			}
		}
	}
	virtual void print()
	{
		for (size_t i = 0; i < x; i++)
		{
			for (size_t j = 0; j < y; j++)
			{
				cout << data[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}

	Matrix operator + (Matrix& matx2)
	{
		if (x != matx2.x || y != matx2.y)
		{
			cout << "Матрицы разного размера!" << endl;
			exit(0);
		}
		if (x == matx2.x && y == matx2.y)
		{
			Matrix temp(x, y);
			for (size_t i = 0; i < x; i++)
			{
				for (size_t j = 0; j < y; j++)
				{
					temp.data[i][j] = data[i][j] + matx2.data[i][j];
				}
			}
			return temp;
		}
	}

	Matrix add_matrix(Matrix matx2)
	{
		Matrix temp(x, y);
		if (x == matx2.x && y == matx2.y)
		{
			for (size_t i = 0; i < x; i++)
			{
				for (size_t j = 0; j < y; j++)
				{
					temp.data[i][j] = data[i][j] + matx2.data[i][j];
				}
			}
			return temp;
		}
		else
		{
			Matrix temp(1, 1);
			return temp;
		}
	}

	Matrix& operator*(int scal)
	{
		for (size_t i = 0; i < x; i++)
		{
			for (size_t j = 0; j < y; j++)
			{
				data[i][j] = data[i][j] * scal;
			}
		}
		return *this;
	}

	void perestanovra_vector(int vector[])
	{
		for (int i = 0; i < 3; i++)
		{
			cout << "[" << i << "]: ";
			while (true)
			{
				cin >> vector[i];
				if (cin.good() && vector[i] <= 3 && vector[i] >= 1)
				{
					cin.ignore(10, '\n');
					break;
				}
				cin.clear();
				cin.ignore(10, '\n');
			}
		}
		for (int i = 0; i < x; i++)
		{
			for (int j = 0; j < y; j++)
			{
				int k = vector[i];
				int temp = data[i][j];
				data[i][j] = data[k - 1][j];
				data[k - 1][j] = temp;
			}
		}
	}
};

class Matrix_square :public Matrix
{
	int n;
public:
	Matrix_square() {}
	Matrix_square(int nn) : Matrix(nn, nn)
	{
		n = nn;
	}

	Matrix_square operator + (Matrix_square& matx2)
	{
		if (x != matx2.x || y != matx2.y)
		{
			cout << "Матрицы разного размера!" << endl;
			exit(0);
		}
		if (x == matx2.x && y == matx2.y)
		{
			Matrix_square temp(n);
			for (size_t i = 0; i < x; i++)
			{
				for (size_t j = 0; j < y; j++)
				{
					temp.data[i][j] = data[i][j] + matx2.data[i][j];
				}
			}
			return temp;
		}
	}


	void transpose()
	{
		for (size_t i = 0; i < n; i++)
		{
			for (size_t j = i; j < n; j++)
			{
				int temp = data[i][j];
				data[i][j] = data[j][i];
				data[j][i] = temp;
			}
		}
	}

	Matrix_square operator*(Matrix_square& mat1)
	{
		Matrix_square temp(mat1.n);
		for (size_t i = 0; i < mat1.n; i++)
		{
			for (size_t k = 0; k < mat1.n; k++)
			{
				for (size_t j = 0; j < mat1.n; j++)
				{
					temp.data[i][k] += data[i][j] * mat1.data[i][j];
				}
			}
		}
		return temp;
	}

	~Matrix_square() {}
};

int main()
{
	setlocale(LC_ALL, "rus");
	Matrix m1(3, 4);
	cout << "Введите Матрицу №1 размером 2 на 3:    (буквы считаются нулём!)" << endl;  m1.enter();
	Matrix m2(3, 4);
	cout << "Введите матрицу №2 размером 3 на 2:    (буквы считаются нулём!)" << endl;  m2.enter();
	Matrix m3(3, 4);
	cout << "Матрица №1: " << endl; m1.print();
	cout << "Матрица №2: " << endl; m2.print();
	m1 = m1 * 2;
	cout << "Результат умножения Матрицы №1 на 2: " << endl; m1.print();
	m3 = m1 + m2;
	cout << "Результат сложения двух матриц: " << endl;  m3.print();

	//перестановка строк матрицы по заданному вектору транспозиции
	int vector[3];
	cout << "Введите координаты вектора транспозиции:" << endl;
	m3.perestanovra_vector(vector);
	cout << endl << "Матрица сложения после перестановки по вектору транспозиции { " << vector[0] << ", " << vector[1] << ", " << vector[2] << " }:" << endl;
	m3.print();

	system("pause");
	system("cls");

	Matrix_square mk1(3);
	cout << "Введите Матрицу №1:    (буквы считаются нулём!)" << endl;  mk1.enter();
	Matrix_square mk2(3);
	cout << "Введите Матрицу №2:    (буквы считаются нулём!)" << endl; mk2.enter();
	cout << "Матрица №1: " << endl; mk1.print();
	cout << "Матрица №2: " << endl; mk2.print();
	cout << "Матрица №2 после транспонирования: " << endl; mk2.transpose();  mk2.print();
	Matrix_square mk4(3);
	mk4 = mk1 + mk2;
	cout << "Результат сложения Матрицы №1 и Матрицы №2" << endl;
	mk4.print();
	Matrix_square mk3(3);
	mk3 = mk1 * mk2;
	cout << "Результат перемножения Матрицы №1 и Матрицы №2" << endl;
	mk3.print();
	system("pause");
}