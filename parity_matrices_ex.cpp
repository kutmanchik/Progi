#include<iostream>
using namespace std;

int CheckSum(int arr[], int Msize);
int CheckPosition(int arr[], int Msize);

int main()
{
    int Matrix_size;
    while(cin >> Matrix_size)
    {
      if( Matrix_size == 0)
      {
        break;
      }

      int Matrix[100][100] = {0};
      int elem_size = Matrix_size * Matrix_size;
      int input[elem_size + 1];
      int j = 0, k = 0;
      int sum_row[101] = {0}, sum_column[101] = {0};

      for(int i = 1; i < elem_size + 1;i++)
      {
        cin >> input[i];
      }

      for(int i = 1; i < elem_size + 1; i++)
      {
        Matrix[j][k] = input[i];
        k++;
        if(i % Matrix_size == 0)
        {
          j++; // Row
          k = 0;
          }
        }

        k = 0; // reset
        j = 0; // reset

        for(int i = 1 ; i <= elem_size ; i++)
        {
          sum_row[j+1] += Matrix[j][k];
          k++;
          if(i % Matrix_size == 0)
          {
            j++;
            k = 0;
          }
        }

        k = 0; // reset
        j = 0; // reset

        for(int i = 1 ; i <= elem_size ; i++)
        {
          sum_column[j+1] += Matrix[k][j];
          k++;
          if(i % Matrix_size == 0)
          {
            j++;
            k = 0;
          }
        }

        int C_row = CheckSum(sum_row , Matrix_size);
        int C_column = CheckSum(sum_column , Matrix_size);

        if( C_row == 0 && C_column == 0 )
        {
          cout << "OK" << endl;
        }
        else if ( C_row == 1 && C_column == 1)
        {
          cout << "Change bit (" << CheckPosition(sum_row, Matrix_size) << ",";
          cout << CheckPosition(sum_column, Matrix_size) << ")" << endl;
        }
        else
        {
          cout << "Corrupt" << endl;
        }
    }
    return 0;
}
int CheckSum(int arr[], int Msize)
{
  int Count = 0;
  for(int i = 1; i < Msize + 1;i++)
  {
    if(arr[i] % 2 != 0)
    {
      Count++;
    }
  }
  return Count;
}

int CheckPosition(int arr[], int Msize)
{
  for(int i = 1; i < Msize + 1;i++)
  {
    if(arr[i] % 2 != 0)
    {
      return i;
    }
  }
}
