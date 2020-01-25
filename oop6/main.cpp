#include <iostream>
#include <string.h>
#include <locale.h>
#include <iomanip>
using namespace std;
class nalogi;
class employee
{
public:
    char *familya;
    int zp;
    float raschet(nalogi);
    employee(char *FAMILYA,int ZP)
    {
        familya=new char[40];
        strcpy(familya,FAMILYA);
        zp=ZP;
    }
    void inpt()
    {
        cout<<"Введите фамилию:"<<endl;
        fflush(stdin);
        gets(familya);
        cout<<"Введите зарплату:"<<endl;
        cin>>zp;
    }
    employee(){}
    ~employee()
    {
        delete [] familya;
    }
    void employee_print();
};
class nalogi
{
public:
    float pd,st;
    friend float employee::raschet(nalogi);
    nalogi(float f1,float f2) : pd(f1),st(f2){};
    ~nalogi(void){};
    void nalogi_print();
};
class form : public employee, public nalogi
{
public:
    form(char *FAMILYA,int ZP,float ST,float PD):employee(FAMILYA,ZP),nalogi(PD,ST){}
    ~form(){};
    friend float employee::raschet(nalogi);
    void form_print();
};

void employee::employee_print()
{
    cout <<setw(10)<< "Фамилия"<<setw(10)<<"Зарплата"<<endl;
    cout<<setw(10)<<familya<<setw(10)<<zp<<endl;
}
void nalogi::nalogi_print()
{
    cout <<setw(10)<<"Подоходный налог"<<setw(10)<<"Налог на соц. страхование"<<endl;
    cout<<setw(10)<<pd<<setw(10)<<st<<endl;
}
void form::form_print()
{
    employee::employee_print();
    nalogi::nalogi_print();
    employee::raschet(nl);
}
float employee::raschet(nalogi nl)
{
    cout<<familya<<setw(6) <<zp<<endl;
    cout<<nl.pd<<setw(8) << nl.st <<endl;
    return zp*nl.pd/100+zp*nl.st/100;
}
int main()
{
    setlocale(LC_ALL,"Russian" );
    nalogi nlg((float)12,(float)2.3);
    char FAMILYA[40];
    int ZP;
    employee wr[2]; // описание массива объектов
    for(int i=0;i<2;i++) wr[i].inpt(); // инициализация массива объктов
    cout << setiosflags(ios::fixed) << setprecision(3) << endl;
    cout<<wr[0].raschet(nlg) <<endl; // расчет налога для объекта wr[0]
    cout<<wr[1].raschet(nlg) <<endl;// расчет налога для объекта wr[1]
    return 0;
}
