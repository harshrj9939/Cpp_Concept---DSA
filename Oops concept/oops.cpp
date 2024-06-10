#include<iostream>
using namespace std;
 class Fruit{
	 public:
	 string name; //properties of class
	 string color;
 };
 int main(){
	 Fruit mango; //object declaration
	 mango.name= "Mango";
	 mango.color= "yellow";

	 cout<< "The properties of fruit is :"<<mango.name<<" - "<<mango.color<<endl;

	 Fruit *Apple = new Fruit();
	 Apple->name = "Apple";
	 Apple->color = "Red";

	 cout<< Apple->name<<" is good for health. "<<Apple->color<<" is the color of "<<Apple->name;

	 return 0;
 };