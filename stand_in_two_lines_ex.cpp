#include <iostream>
#include <queue>
using namespace std;
int main()
{
  int N;
  cin>>N;
  int input[N];
  for(int i = 0; i < N; i++)
  {
    cin>>input[i];
  }
  queue<int>even,odd;
  for (int i = 0; i < N; i++)
  {
    if (input[i] % 2 == 0)
    {
      even.push(input[i]);
    }
    else
    {
      odd.push(input[i]);
    }
  }
  while (!even.empty() || !odd.empty())
  {
    if (!odd.empty())
    {
      cout<<odd.front()<<" ";
      odd.pop();
    }
    if (!odd.empty())
    {
      cout<<odd.front()<<" ";
      odd.pop();
    }
    if (!even.empty())
    {
      cout<<even.front()<<" ";
      even.pop();
    }
  }
  cout<<endl;
  return 0;
}
