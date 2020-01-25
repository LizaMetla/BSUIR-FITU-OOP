# include <iostream>
using namespace std;

class MyString
{

public:
    MyString(void);//default sets string to NULL
    MyString(const char* input);//Takes in a string and creates an object
    MyString(const MyString & S);//Copy constructor
    ~MyString(void);//Destructor deletes the nstring at the end


    int length();//displays length of string excluding null
    bool is_empty();// if string is empty returns true else it returns false



    friend ostream& operator << (ostream & OS,const MyString &S);// out stream displays the string
    friend istream& operator >> (istream & IS,MyString &S);//instream takes in a string and creates and object
    MyString& operator = (const MyString& S);//if A and B are object B is "neil", the A =B therefore A is "neil"
    friend  bool operator ==(const MyString& S1, const MyString & S2);// checks if both strings are equal
    friend MyString operator + (const MyString& S1, const MyString & S2);//still buggy
    MyString operator ~ (){
        *this = *this + *this;
        return *this;
    }
    MyString operator ++ (const int){
        *this = *this + MyString(".");
        return *this;
    }

private:
    char* nstring;
    short nlength;
};
