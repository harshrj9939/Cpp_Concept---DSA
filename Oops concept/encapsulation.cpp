#include<iostream>
using namespace std;

 class Rectangle{
    int x;
    public:

    void set(int n){
        x = n;
    }

    int get(){
        return x;
    }
 };
int main(){
    Rectangle r;
    r.set(3);
    cout<<r.get()<<endl;
    return 0;
}
