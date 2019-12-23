#include <string.h>
#include <iostream>

using namespace std;

int main()
{
  int deposit,result,withdraw,number;
  char password[12], check[12];
  while(cin>>password>>deposit)
  {
    while(cin>>number)
    {
      if(number==1)
      {
        cin>>check;
        result = strcmp(password,check);
        if(result == 0)
        {
          cout<<"Login succesfuly!"<<endl;
        }
        else
        {
          cout<<"incorrect Password"<<endl;
        }
      }
      else if(number==2)
      {
        cin>>withdraw;
        deposit -= withdraw;
        if(deposit < 0)
        {
          cout<<"Insufficient balance"<<endl;
          deposit += withdraw;
        }
      }
      else if(number == 3)
      {
        cin>>withdraw;
        deposit += withdraw;
      }
      else if(number == 4)
      {
        cout<<deposit<<endl;
      }
      else if(number == 0)
      {
        break;
      }
    }
  }

  return 0;
}
