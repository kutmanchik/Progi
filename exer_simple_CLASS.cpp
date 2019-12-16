#include <iostream>
#include <string>
using namespace std;

class MyClass {
public:
  void myMethod() {
    cout<< "Hello World!"<<endl;
  }
};

class Hehe  {
public:
  void h();
};

class Car {
  public:
    string brand;
    string model;
    int year;
};

  void Hehe :: h()
  {
    cout<<"hello programmer\n";
    std::cout << "" << '\n';
  }
int main() {

  Hehe ob;
  ob.h();

  MyClass myOb;
  myOb.myMethod();

  Car bmw;
  bmw.brand = "BMW";
  bmw.model = "X5";
  bmw.year = 1993;

  Car ford;
  ford.brand = "Ford";
  ford.model = "Mustang";
  ford.year = 1969;

  cout << bmw.brand << " " << bmw.model << " " << bmw.year << "\n";
  cout << ford.brand << " " << ford.model << " " << ford.year << "\n";
  return 0;
}
