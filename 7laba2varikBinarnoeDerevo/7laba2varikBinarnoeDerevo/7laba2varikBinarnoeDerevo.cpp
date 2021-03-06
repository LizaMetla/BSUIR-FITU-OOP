// 7laba2varikBinarnoeDerevo.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

int menu();
void Second();

template <class T> class TreeNode
{
public:
	TreeNode < T > *left;
	TreeNode < T > *right;
	virtual void show(TreeNode<T> *element) = 0;
	virtual void Add_element(TreeNode<T> *element, int x) = 0;
	int x;
};

template <class T> class Tree : public TreeNode < T >
{
	int hl = 0;
public:
	void show(TreeNode<T> *element);
	void Add_element(TreeNode<T> *element, int x);
};

template < class T> void Tree < T > ::Add_element(TreeNode<T> *element, int x)
{
	if (hl == 0)
	{
		element = new Tree;
		element->x = x;
		element->left = NULL;
		element->right = NULL;
		hl = 1;
	}
	if (x < element->x)
	{
		if (element->left != NULL)
			Add_element(element->left, x);

		else
		{
			element->left = new Tree;
			element->left->left = NULL;
			element->left->x = x;
		}
	}
	if (x > element->x)
	{
		if (element->right != NULL)
		{
			Add_element(element->right, x);
		}
		else
		{
			element->right = new Tree;
			element->right->right = NULL;
			element->right->x = x;
		}
	}
}

template < class T> void Tree < T > ::show(TreeNode<T> *element)
{
	if (element != NULL)
	{
		show(element->left);
		cout << element->x << " ";
		show(element->right);
	}
}

void Second()
{
	int choise = 0, i = 0;
	while (i != 1)
	{
		cout << "Меню Задания 2" << endl;
		cout << "Выберете пункт: " << endl;
		cout << "1. Ввести значения в дерево" << endl;
		cout << "8. Выход" << endl;
		cin >> choise;
		switch (choise)
		{
		case 1:
		{
			TreeNode <int> *a1;
			Tree <int> a2;
			int xl = 1, b;
			a1 = &a2;
			while (xl == 1)
			{

				cout << "Введите число в дерево: ";
				cin >> b;
				a1->Add_element(a1, b);
				cout << "Ввести еще одно число? Да/Нет(1/0): ";
				cin >> xl;
				a1->show(a1);
			}
			system("pause");
			break;
		}
		case 2:
		{

		}
		case 8:
		{
			i = 1;
		}
		}
	}
}

int menu()
{
	int choise = 0, i = 0;
	while (i != 1)
	{
		cout << "Добро пожаловать!" << endl;
		cout << "Выберете пункт: " << endl;
		cout << "1. Поиск максимального (Задание 1)" << endl;
		cout << "2. Задание 2" << endl;
		cout << "8. Выход" << endl;
		cin >> choise;
		switch (choise)
		{
		case 1:
		{
			First();
			break;
		}
		case 2:
		{
			Second();
			break;
		}
		case 8:
		{
			return 0;
		}
		}
	}
	return 0;
}

int main()
{
	setlocale(LC_ALL, "Rus");
	int r = 1;
	while (r != 0)
	{
		r = menu();
	}
	system("pause");
	return 0;
}