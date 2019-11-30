#include <iostream>
using namespace std;

int main()
{
  int num, count;
  count = 0;
  while(cin>>num)
  {
    int l[num];
    for(int i = 0; i < num; i++)
    {
      cin>>l[i];
    }
    if(num == 0)
    {
      count = 0;
      break;
    }
    int sum = 0;
    for (int i = 0; i < num; i++)
    {
      sum += l[i];
    }
    int avg = 0;
    avg = sum/num;
    int r = 0;
    for(int i = 0; i < num; i++)
    {
      if(l[i]<avg)
      {
        r += avg - l[i];
      }
    }
    count++;
    cout<<"Set #"<<count<<endl;
    cout<<"The minimum number of moves is "<<r<<"."<<endl;
  }
  return 0;
}
