#include <iostream>
using namespace std;

class Car
{
public:
  string brand;
  string model;
  int year;
  Car(string x, string y, int z)
  {
    brand = x;
    model = y;
    year = z;
  }
};
class MyClass
{
public:
  MyClass()
  {
    cout<< "Hello World!\n";
  }
};

int main()
{
  Car carob("Bmw","samurai",2019);
  Car carob2("mers","w220",1990);
  cout<<carob.brand<<" "<<carob.model<<" "<<carob.year<<endl;
  cout<<carob2.brand<<" "<<carob2.model<<" "<<carob2.year<<endl;
  MyClass obj;
  return 0;
}
