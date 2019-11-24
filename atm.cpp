#include <iostream>
#include <string.h>
using namespace std;
int main()
{
   char password[12],check[12];
   int deposit,number,result,withdraw;
   while(cin>>password>>deposit)
   {
     while(cin>>number)
   {
      if(number==1)
        {
          cin>>check;
          result = strcmp(check,password);
          if(result == 0)
              cout<<"Login successfully!"<<endl;
          else
              cout<<"Password is incorrect."<<endl;
        }
      else if(number==2)
        {
          cin>>withdraw;
          deposit-=withdraw;
          if(deposit<0)
            {
               cout<<"Insufficient balance."<<endl;
               deposit+=withdraw;
           }
             }

       else  if(number==3)
        {
          cin>>withdraw;
          deposit+=withdraw;

        }
      else if(number==4)
        {
            cout<<deposit<<endl;
       }
     else if (number==0)
        break;
      }
   }
  return 0;
}
