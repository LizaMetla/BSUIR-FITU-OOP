// 7laba4varik.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <locale.h>
#include <string>
using namespace std;

template<typename T>
struct element
{
	T information;
	element *next;
};


template <typename T>
class list
{
	element<T> *head;
public:
	list(element<T>  *n) : head(n) {}

	list() : head(NULL) {}
	int print_list();
	void push_start_element(T);
	void push_back_element(T);
	int delete_element(int);
	int find_element(T);
	element<T> * last_element();
	int size_list();
	bool isEmpty();

	ostream& operator<<(T &temp)
	{
		cout << temp;
		return cout;
	}
};

template<typename T>
int list<T>::print_list()
{
	if (head == NULL)
	{
		cout << "Список пуст!" << endl;
		return 0;
	}
	element<T>  *ptr = head;
	do
	{
		cout << ptr->information << " ";
		ptr = ptr->next;
	} while (ptr->next);
	cout << ptr->information << endl;
	return 0;
}

template<typename T>
void list<T>::push_start_element(T data)
{
	element<T>  *temp = new element<T>[1];
	temp->information = data;
	temp->next = head;
	head = temp;
}

template<typename T>
element<T>* list<T>::last_element()
{
	if (head == NULL) return head;
	element<T>  *ptr = head;
	do {
		if (ptr->next) ptr = ptr->next;
		else return ptr;
	} while (true);
}

template <typename T>
void list<T>::push_back_element(T data)
{
	element<T>  *temp = new element<T>[1];
	element<T>  *last = last_element();
	last->next = temp;
	temp->information = data;
	temp->next = NULL;
}

template<typename T>
int list<T> ::find_element(T data)
{
	element<T>  *temp = head;
	if (temp == NULL)
	{
		cout << "Список пуст!" << endl;
		return 0;
	}
	int counter = 1;
	do {
		if (temp->information == data) cout << "Такой элемент на месте номер " << counter << endl;
		temp = temp->next;
		counter++;
	} while (temp->next);
}

template <typename T>
int list<T> ::delete_element(int n)
{
	element<T>  *temp = head;
	if (temp == NULL)
	{
		cout << "Список пуст!" << endl;
		return 0;
	}
	if (n == 1) {
		element<T>  *del = new element<T>;
		del = temp;
		temp = head = temp->next;
		cout << "Удалён";
		//delete del;
		return 0;
	}
	int counter = 2;
	int sizeList = size_list();
	do
	{
		if (counter > n || counter > sizeList)
		{
			cout << "Элемента с номером " << n << " в списке нету!" << endl;
			return 0;
		}
		if (counter == n)
		{
			element<T>  *del = new element<T>;
			del = temp->next;
			if (del == NULL) temp->next = NULL;
			else temp->next = del->next;
			cout << "Удалён";
			//delete del;
			return 0;
		}
		else
		{
			counter++;
			temp = temp->next;
			if (temp == NULL)
			{
				cout << "Элемента с номером " << n << " в списке нету!" << endl;
				return 0;
			}
		}
	} while (true);
}

template <typename T>
int list<T> ::size_list()
{
	element<T> * temp = head;
	if (temp == NULL) return 1;
	int size = 1;
	while (temp->next)
	{
		temp = temp->next;
		size++;
	}
	return size;
}

template <typename T>
bool list<T> ::isEmpty()
{
	if (head == NULL) return true;
	else return false;
}

#define TYPES "1. int\n"\
			"2. String"\
			"3. Выход\n\n>>"

int main()
{
	setlocale(LC_ALL, "rus");
	cout << "РАБОТА С ТИПОМ int:" << endl << endl;
	list<int> list1;
	cout << "Вывод списка после создания:\t\t\t";  list1.print_list();
	cout << "Проверка на пустоту: ";
	if (list1.isEmpty()) cout << "Пуст" << endl;
	else cout << "Не пуст" << endl;
	cout << "Добавление элемента 10 в начало" << endl;
	list1.push_start_element(10);
	cout << "Добавление элемента 20 в начало" << endl;
	list1.push_start_element(20);
	cout << "Добавление элемента 30 в начало" << endl;
	list1.push_start_element(30);
	cout << "Добавление элемента 40 в конец" << endl;
	list1.push_back_element(40);
	cout << "Добавление элемента 50 в конец" << endl;
	list1.push_back_element(50);
	cout << "Проверка на пустоту: ";
	if (list1.isEmpty()) cout << "Пуст" << endl;
	else cout << "Не пуст" << endl;
	cout << "Вывод списка после добавления 5ти элементов:\t";
	list1.print_list();
	cout << "Добавление элемента 70 в начало" << endl;
	list1.push_start_element(70);
	cout << "Вывод списка после добавления еще 1 элемента:\t"; list1.print_list();
	cout << "Поиск элемента 30:\t\t\t\t"; list1.find_element(30); cout << endl;
	cout << "Удаление 1го элемента:\t\t\t"; list1.delete_element(1); cout << endl;
	cout << "Удаление 3го элемента:\t\t\t"; list1.delete_element(3); cout << endl;
	cout << "Удаление 4го элемента:\t\t\t"; list1.delete_element(4); cout << endl;
	cout << "Удаление 45го элемента:\t\t\t"; list1.delete_element(45); cout << endl;
	cout << "Вывод списка после удаления 3 элементов:\t"; list1.print_list();

	cout << endl << "РАБОТА С ТИПОМ string:" << endl << endl;
	list<string> list2;
	cout << "Вывод списка после создания:\t\t\t";  list2.print_list();
	string s1("Первый");
	string s2("Второй");
	string s3("Третий");
	string s4("Четвертый");
	string s5("Пятый");
	string s6("Шестой");
	string s7("Седьмой");
	cout << "Добавление элемента \"Первый\" в начало" << endl;
	list2.push_start_element(s1);
	cout << "Добавление элемента \"Второй\" в начало" << endl;
	list2.push_start_element(s2);
	cout << "Добавление элемента \"Третий\" в начало" << endl;
	list2.push_start_element(s3);
	cout << "Добавление элемента \"Четвертый\" в конец" << endl;
	list2.push_back_element(s4);
	cout << "Добавление элемента \"Пятый\" в конец" << endl;
	list2.push_back_element(s5);
	cout << "Вывод списка после добавления 5ти элементов:\t"; list2.print_list();
	cout << "Добавление элемента \"Шестой\" в начало" << endl;
	list2.push_start_element(s6);
	cout << "Вывод списка после добавления 1 элемента:\t"; list2.print_list();
	cout << "Поиск элемента \"Второй\":\t\t\t\t"; list2.find_element(s2); cout << endl;
	cout << "Удаление 1го элемента:\t\t\t"; list2.delete_element(1); cout << endl;
	cout << "Удаление 3го элемента:\t\t\t"; list2.delete_element(3); cout << endl;
	cout << "Удаление 4го элемента:\t\t\t"; list2.delete_element(4); cout << endl;
	cout << "Удаление 45го элемента:\t\t\t"; list2.delete_element(45); cout << endl;
	cout << "Вывод списка после удаления 3 элементов:\t"; list2.print_list();
	system("pause");
}