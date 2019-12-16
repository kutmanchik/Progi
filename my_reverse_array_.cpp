#include <iostream>
using namespace std;
void reverse_array(int arr[], int start , int end);
void print_array(int arr[], int size);
int main()
{
  int arr[]={1,2,3,4,5,6,7};
  int n = sizeof(arr)/ sizeof(arr[0]);
  print_array(arr,n);
  reverse_array(arr, 0 , n-1);
  cout<< "reversed array: "<<endl;
  print_array(arr,n);

  return 0;
}

void reverse_array(int arr[], int start, int end)
{
  while (start < end)
  {
    int temp = arr[start];
    arr[start] = arr[end];
    arr[end]= temp;
    start ++;
    end --;
  }
}
void print_array(int arr[], int size)
{
  for (int i = 0; i < size; i++)
  {
    cout<< arr[i]<<" ";
  }
  cout<<endl;
}
