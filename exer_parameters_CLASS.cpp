#include <iostream>
using namespace std;

class Car
{
public:
  int speed(int maxSpeed);
};

int Car :: speed(int maxSpeed)
{
  return maxSpeed;
}

int main()
{
  Car bmw, mers;
  cout<<"mers: "<< mers.speed(190) << endl;
  cout<< "bmw: "<< bmw.speed(200) << endl;
  return 0;
}
