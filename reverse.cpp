#include <iostream>
#include <string.h>
using namespace std;
int main()
{
  char ch[50],temp;
  int num,i,j;
  cin>>num;
  for(int a=0;a<num;a++)
{
  cin>>ch;
  j=strlen(ch)-1;
  for(i=0;i<j;i++,j--)
{
  temp=ch[i];
  ch[i]=ch[j];
  ch[j]=temp;
}
  cout<<ch<<endl;
}
  return 0;
}
