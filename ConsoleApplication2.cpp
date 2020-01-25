#include <iostream>
#include <string>

class Product
{
private :
    std::string name;
    std::string manufacturer;
    double price;

public :
    Product()
    {

        this->name = "";
        this->manufacturer = "";
        price = NULL;
    }

    Product(std::string name, std::string manufacturer, double price)
    {

        this->name = name;
        this->manufacturer = manufacturer;
        this->price = price;
    }

    Product(const Product& product)
    {

        this->name = product.name;
        this->manufacturer = product.manufacturer;
        this->price = product.price;
    }

    std::string getName()
    {
        return name;
    }

    std::string getManufacturer()
    {
        return manufacturer;
    }

    double getPrice()
    {
        return price;
    }

    void setName(std::string name)
    {
        this->name = name;
    }

    void setManufacturer(std::string manufacturer)
    {
        this->manufacturer = manufacturer;
    }

    void setPrice(double price)
    {
        this->price = price;
    }
};

class Department : public Store
{
private :
    std::string name;

public:
    Department():Store()
    {

        this->Department::name = "";
    }

    Department(std::string name)
    {

        this->Department::name = name;
    }

    Department(const Department& department)
    {

        this->Department::name = department.name;;
    }

    std::string getName()
    {
        return Department::name;
    }

    void setName(std::string name)
    {
        this->Department::name = name;
    }
};

class Store
{
private :
    std::string name;
    std::string type;

public:
    Store()
    {

        this->name = "";
        this->type = "";
    }

    Store(std::string name, std::string type)
    {

        this->name = name;
        this->type = type;
    }

    Store(const Store& store)
    {

        this->name = store.name;
        this->type = store.type;
    }
    std::string getName()
    {
        return name;
    }
    std::string getType()
    {
        return type;
    }
    void setName(std::string name)
    {
        this->name = name;
    }
    void setType(std::string type)
    {
        this->type = type;
    }
};

class Basket: public Product
{
private :
    double sum;

public:
    Basket() : Product()
    {
       this->sum = NULL;
    }
    Basket(double sum)
    {
        this->sum = sum;
    }
    Basket(const Basket& basket)
    {
        this->sum = basket.sum;
    }
    double getSum()
    {
        return sum;
    }
    void setSum(double sum)
    {
        this->sum = sum;
    }
};

class Bank
{
private :
    long long accountNum;
    double accountSum;

public :
    Bank()
    {
        accountNum = NULL;
        accountSum = NULL;
    }
    Bank(long long accountNum, double accountSum)
    {
        this->accountNum = accountNum;
        this->accountSum = accountSum;
    }
    Bank(const Bank& bank)
    {
        this->accountNum = bank.accountNum;
        this->accountSum = bank.accountSum;
    }
    long long getAccountNum()
    {
        return accountNum;
    }
    double getAccountSum()
    {
        return accountSum;
    }
    void setAccountSum(double accountSum)
    {
        this->accountSum = accountSum;
    }
    void setAccountNum(long long accountNum)
    {
        this->accountNum = accountNum;
    }
};

class Buyer : public Bank
{
private:
    std::string name;
public:
    Buyer(): Bank()
    {
        this->name = "";
    }
    Buyer(std::string name)
    {
        this->name = name;
    }
    Buyer(const Buyer& buyer)
    {
        this->name = buyer.name;
    }
    std::string getName()
    {
        return this->name;
    }
    void setName(std::string name)
    {
        this->name = name;
    }
    
    bool buyBasket(Basket& basket)
    {
        if (this->getAccountSum() >= basket.getSum())
        {
            this->setAccountSum(this->getAccountSum() - basket.getSum());
            return true;
        }
        return false;
    }
};

int main()
{
    std::cout << "Hello World!\n";
}