#include <iostream>
#include <cctype>
#include <string>

using namespace std;

struct student
{
  int id;
  int score;
};

void Swap(int &x, int &y)
{
  int temp = x;
  x = y;
  y = temp;
}

void bubbleSort(int *arr, int n)
{
  for(int i = 0; i < n-1 ; i++)
  {
    for (int j = 0; j < n-i-1; j++)
    {
      if (arr[j] > arr[j+1])
      {
        Swap( arr[j], arr[j+1]);
      }
    }
  }
}

void sort_student(student *S, int n)
{
  for(int i = 0 ; i < n - 1 ; i++)
  {
    for(int j = 0 ; j < n - i - 1 ; j++)
    {
      if( S[j].score > S[j+1].score )
      {
        Swap( S[j].score, S[j+1].score );
        Swap( S[j].id, S[j+1].id);
      }
    }
  }

  for(int i = 0 ; i < n - 1 ; i++)
  {
    for(int j = 0 ; j < n - i - 1 ; j++)
    {
      if( S[j].score == S[j+1].score )
      {
        if(S[j].id > S[j+1].id)
        {
          Swap( S[j].score, S[j+1].score );
          Swap( S[j].id, S[j+1].id);
        }
      }
    }
  }
}

int main()
{
  int N;
  cin >> N;
  student* S = new student[N];

  for(int i = 0 ; i < N ; i++)
  {
    cin >> S[i].id >> S[i].score;
  }

  sort_student(S, N);
  for(int i = 0 ; i < N ; i++)
  {
    cout << S[i].id << " " << S[i].score << endl;
  }
  return 0;
}
