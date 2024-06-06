#include<iostream>
using namespace std;

class Parent{
    public:
    int x;

    protected:
    int y;

    private:
    int z;
    
    

};

class child1: public Parent{
    //x will remain public
    //y will remain protected
    //z will remain inaccesable
};
class child2: private Parent{
    //x will remain public
    //y will remain public
    //z will remain inaccesable
};
class child3: protected Parent{
    //x will remain protected
    //y will remain protected
    //z will remain inaccesable
};
int main(){
    Parent p;
    p.x =1;
    cout<<p.x<<endl;
return 0;
}



 
