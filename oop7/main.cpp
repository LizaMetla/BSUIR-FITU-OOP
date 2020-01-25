#include <iostream>
#include <string>
//ptmp это временная переменная для всякой текучки
//ph это указатель на головной узел списка
template<class T>
class list
{
public:
    list() : ph(0){}
    void push_front(T const& val)
    {
        node* ptmp = ph;
        ph = new node(val);
        ph->next = ptmp;
    }
    void push_back(T const& val)
    {
        if(!ph)
            ph = new node(val);
        else
        {
            node* ptmp = ph;
            while(ptmp->next)
                ptmp = ptmp->next;
            ptmp->next = new node(val);
        }
    }
    void erase(T const& val)
    {
        while(ph && ph->data == val)
        {
            node* ptmp = ph;
            ph = ph->next;
            delete ptmp;
            ptmp = 0;
        }

        node* ptmp = ph;
        while(ptmp && ptmp->next)
        {
            while(ptmp->next && ptmp->next->data == val)
            {
                node* ptmp1 = ptmp->next;
                ptmp->next = ptmp->next->next;
                delete ptmp1;
                ptmp1 = 0;
            }
            ptmp = ptmp->next;
        }
    }
    size_t count(T const& val)const
    {
        node* ptmp = ph;
        size_t cntr = 0;
        while(ptmp)
        {
            if(ptmp->data == val)
                ++cntr;
            ptmp = ptmp->next;
        }
        return cntr;
    }
    bool empty()const
    {
        return !static_cast<bool>(ph);
    }
    void print()const
    {
        node* ptmp = ph;
        while(ptmp)
        {
            std::cout << ptmp->data << '\n';
            ptmp = ptmp->next;
        }
    }
    ~list()
    {
        node* ptmp = 0;
        while(ph)
        {
            ptmp = ph;
            ph = ph->next;
            delete ptmp;
        }
    }
private:
    struct node
    {
        node() : next(0){}
        node(T const& val) : next(0), data(val){}
        T data;
        node* next;
    };
    node* ph;
    list(list const&);
    list& operator=(list);
};

int main()
{
    list<int> lst;
    list<std::string> lsts;
    lst.push_back(10);
    lst.push_front(10);
    lst.push_back(10);
    lst.push_back(10);
    lst.erase(10);
    lst.push_back(88);
    lsts.push_back("ggg");
    lst.push_back(16);
    lst.push_back(10);
    lsts.push_front("fff");
    lsts.print();
    std::cout << lsts.count("ff") << '\n';
    return 0;
}
