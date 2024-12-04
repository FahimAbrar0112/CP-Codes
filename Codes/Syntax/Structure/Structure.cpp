#include <bits/stdc++.h>
using namespace std;

struct Person
{
    // public:
private:
    string name;
    int id;

public:
    Person()
    {

    }
    
    Person(string name,int id)
    {
        this->name=name;
        this->id=id;
    }

    void printP()
    {
        cout << name << " " << id << endl;
    }

    void setter(string name, int id)
    {
        this->name = name;
        this->id = id;
    }
};

int main(void)
{
    Person p;

    p.setter("FUAD", 123);

    p.printP();

    Person p2("ASIF",69);
    p2.printP();
}