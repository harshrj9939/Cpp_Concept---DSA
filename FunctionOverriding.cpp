#include <iostream>
using namespace std;
//this is the concept of run time polymorphism
class Parent{
    public:

    virtual void print(){
        cout<<"Parent class"<<endl;
    }
    void show(){
        cout<<"Parent class"<<endl;
    }
};
class Child: public Parent{
    public:
    void print(){
        cout<<"child class"<<endl;
    }
    void show(){
        cout<<"child class"<<endl;
    }
};

int main(){
    Parent *p;
    Child c;

    p = &c;
    p->print();
    p->show();
    return 0;
}
