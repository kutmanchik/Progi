#include <iostream>
#include <string>
using namespace std;


void removes(char* str)
{
  int count = 0;
  for (int i =0; str[i]; i++)
  {
    if(str[i] != ' ')
    {
      str[count++]= str[i];
    }
  }
  str[count] = '\0';
}
int main()
{
  int size =80;
  char str[size];
  cin.getline(str,size);
  str[0]= toupper(str[0]);
  for(int i = 1; i < size; i++)
  {
    if(str[i-1] == ' ')
    {
      str[i] = toupper(str[i]);
    }
  }
  removes(str);
  cout<<str<<endl;
  return 0;
}
