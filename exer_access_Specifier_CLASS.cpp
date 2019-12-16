#include <iostream>
using namespace std;

class Car
{
public:
  int setSalary(int s)
  {
    salary = s;
    return salary;
  }
  /*int getSalary()
  {
    return salary;
  }*/
private:
  int salary;
};

int main()
{

  Car ob;
  cout<< ob.setSalary(300000);
  return 0;
}
