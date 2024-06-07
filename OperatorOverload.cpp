#include<iostream>
using namespace std;
//this is the concept of compile time polymorphism
class Complex{
public:

    int real;
    int imag;
    Complex(int x, int y){
        real = x;
        imag = y;
    }
    Complex operator+ (Complex &c){
            Complex ans(0,0);
            ans.real = real + c.real;
            ans.imag = imag + c.imag;
            return ans;
    }
};
int main (){
    Complex c1(1,2);
    Complex c2(1,3);

    Complex c3 = c1+c2;
    cout<<c3.real<<" i"<<c3.imag<<endl;
    return 0;
}