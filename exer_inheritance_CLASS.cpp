#include <iostream>
using namespace std;

class Vehicle
{
public:
  string brand = "ford";
  void honk()
  {
    cout<< "Tuut, tuut!\n";
  }
};


class Car : public Vehicle
{
public:
  string model = "Mustang";
};


class MyClass {
  public:
    void myFunction() {
      cout << "Some content in parent class." ;
    }
};


// Derived class (child)
class MyChild: public MyClass {
};


// Derived class (grandchild)
class MyGrandChild: public MyChild {
};


int main()
{
  Car mycar;
  mycar.honk();
  cout<< mycar.brand + " " + mycar.model <<endl;
  MyGrandChild myObj;
  myObj.myFunction();
  return 0;
}
