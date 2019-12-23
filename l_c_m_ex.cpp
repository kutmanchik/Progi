#include <iostream>
using namespace std;

int gcd(int a , int b);
int lcm(int arr[], int n);

int main()
{
  int n,m,arr[100];
  while(cin>>m)
  {
    while(cin>>n)
    {
      for (int i=0; i<n; i++)
      {
        cin>>arr[i];
      }
      cout<<lcm(arr,n)<<endl;
    }
  }
  return 0;
}

int gcd(int a, int b)
{
  if(a==0 || b == 0)
  {
    return 0;
  }
  else if(a == b)
  {
    return a;
  }
  else if(a < b)
  {
    return gcd(a, b-a);
  }
  else
  {
    return gcd(a-b, b);
  }
}
int lcm(int arr[], int n)
{
  int answer = arr[0];
  for (int i=1; i<n; i++)
  {
    answer = (((arr[i] * answer))/(gcd(arr[i],answer)));
  }
  return answer;
}
