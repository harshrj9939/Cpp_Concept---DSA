#include<iostream>
using namespace std;

class Parent1{                                      //parent1 class
public:
    Parent1()
    {
        cout<<"Parent1 class "<<endl;
    }
};

// class Parent2{                                      //parent2 class
// public:
//     Parent2()
//     {
//         cout<<"Parent2 class "<<endl;
//     }
// };

class Child1: public Parent1{        //child class inheriting from both parents
    public:         
    Child1(){
        cout<<"Child1 class"<<endl;
    }
};

class Child2: public Parent1{        //child class inheriting from both parents
    public:         
    Child2(){
        cout<<"Child2 class"<<endl;
    }
};
// class grandchild: public Child{             //Grandchild inheriting its immediate parent class
//     public:                                 //Multi-level-inheritance
//     grandchild(){
//         cout<<"GC class"<<endl;
//     }
// };
int main(){
    
    Child1 c;
    Child2 c2;
    return 0;
}