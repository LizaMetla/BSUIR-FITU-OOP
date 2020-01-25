
#include "my_string.h"
# include <iostream>
# include <cstring>

using namespace std;

/*temp = is a temporary variable*/

MyString::MyString()
{
    nlength = 1;
    nstring = new char[nlength];
    nstring[nlength-1] = '\0';
}

MyString::MyString(const char *input) //конструктор c max
{
    // Count how many characters we need to store the input string
    for (nlength = 0; input[ nlength ] != 0; nlength++);
    // Also count the terminating nul character
    nlength += 1;
    // Get space from the heap for the string
    nstring = new char[ nlength ];
    // Copy all the characters, including the terminating nul, into our heap space
    for (int i = 0; i < nlength; i++)
        nstring[ i ] = input[ i ];
}

MyString::MyString(const MyString& S) //конструктор копирования
{
    nlength = S.nlength;
    nstring = new char[nlength];
    for(int i = 0; i < (nlength - 1); i++)
    {
        nstring[i] = S.nstring[i];
    }

    if(nstring[nlength - 1] != '\0'){nstring[nlength -1] = '\0';}
}

MyString::~MyString()
{
    delete[] nstring;
}


int MyString::length()
{
    int i = 0;
    while(nstring[i] != '\0')
    {i++;}
    return i;
}


bool MyString::is_empty()
{
    if(nstring[0] == '\0' && nlength == 1){return true;}
    else {return false;}
}

bool operator == (const MyString & S1, const MyString & S2)
{
    if(S1.nlength == S2.nlength)
    {
        short counter1 = S1.nlength;
        int counter2 = 0;
        int i = 0;
        while(i != counter1)
        {
            if(S1.nstring[i] != S2.nstring[i]){counter2++;}
            i++;
        }
        cout << i << " " << counter2 << endl;
        if(counter2 != 0) {return false;}
        else{return true;}
    }
    else {return false;}

}

ostream& operator <<(ostream & OS, const MyString& S) // для cout
{
    OS << S.nstring;
    return OS;
}

istream& operator >>(istream & IS,MyString& S) // для cin
{
    char* input = new char[100];
    IS.getline(input,100);

    int i = 0;
    while(input[i] != '\0')
    {i++;}
    S.nlength = i+1;
    delete[]S.nstring;
    S.nstring = new char[(i+1)];
    for(int j = 0; j < (i) ; j++)
    {
        S.nstring[j] = input[j];
    }
    S.nstring[i] = '\0';
    delete[]input;
    return IS;
}

MyString& MyString::operator =(const MyString &S) // для присвоения строк
{
    nlength = S.nlength;
    delete[] nstring;
    nstring = new char[nlength];
    for(int i = 0 ; i < (nlength -1);i++)
    {
        nstring[i] = S.nstring[i];
    }
    nstring[(nlength -1)] = '\0';
    return *this;
}

MyString operator + (const MyString& S1, const MyString & S2)
{
    int size = (S1.nlength -1) + (S2.nlength -1) +1;
    char * temp = new char[size];
    for(int i = 0; i < (S1.nlength -1);i++)
    {
        temp[i] = S1.nstring[i];
    }

    int j = 0;
    for(short k = S1.nlength - 1 , j=0; k < (size-1) ; k++, j++)
    {temp[k] = S2.nstring[j];}

    if(temp[size -1 ] != '\0'){temp[size -1] = '\0';}

    MyString S3(temp);
    delete[] temp;
    return S3;
}
int main(){
    MyString A("max"),B(A),C;

    cin >> B;//cin" jhon"
    C = A + B;
   // bool a = A == B; для сравнения символа с max
   // cout << a;
    cout << C;
    cout << ++A << '\n'; // удвоение строки
    cout << C++; // к строке добавляю точечку
}
