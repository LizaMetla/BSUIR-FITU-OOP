
#include <iostream>
#include <cmath>
#include <cstdio>
#include <stdio.h>
#include <stdlib.h>
#include <array>
#include <vector>
#include <iomanip>
#include <clocale>

using namespace std;

class A{

    // приватный тип класса
private:
int n;
int m;
int **mas;
   // общий тип класса

public:

    //конструктор с параметрами
    A(int N, int M) {
      n = N;
      m = M;
      mas = new int *[n];

        for (int i = 0; i < n; i++) {
            mas[i] = new int [m];
        }

    }

    void input_mass();

   // void input_mass(){
        // заполнение двумерной матрицы
    //    srand(time(NULL)); // или можно cin

     //   for (int i = 0; i < n; i++)
     //   {
     //       for (int j = 0; j < m; j++)
      //      {
        //        mas[i][j] = (rand() % 10);
          //  }
       // }
    //}

    void output_mass(){
        // печать матрицы
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << mas[i][j] << " ";
            }
            cout << endl;
        }

    }

    int under_main_line(){
        // поиск мин элемента ниже главной д
        int min = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (i > j) {
                    if (mas[i][j] < min) {
                        min = mas[i][j];
                    }
                }
            }
        }
        return min;
    }

    int up_main_line(){
        // поиск мин элемента выше главной д
        int max = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (i > j) {
                    if (mas[i][j] > max) {
                        max = mas[i][j];
                    }
                }
            }
        }
        return max;
    }

      //деструктор для освобождения памяти
    ~A(){
        for (int i = 0; i < n; i++) {
            delete []mas[i];
        }
        delete []mas;
    }
};
void A::input_mass(){
    srand(time(NULL)); // или можно cin

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            mas[i][j] = (rand() % 10);
        }
    }
}

//A::A(int N, int M){
 //   n = N;
  //  m = M;
  //  mas = new int *[n];

  //  for (int i = 0; i < n; i++) {
     //   mas[i] = new int [m];
  //  }};


int main() {
    int n,m;

    std::cout << "Введите количество строк: " <<std::endl;
    cin >>n;
    std::cout << "Введите количество столбцов: " << endl;
    cin >>m;
    A a = A(n, m);
    a.input_mass();
    a.output_mass();
    cout << "Ниже Главной диагонали : " << a.under_main_line() << endl;
    cout << "Выше Главной диагонали : " << a.up_main_line() << endl;

    return 0;
}
