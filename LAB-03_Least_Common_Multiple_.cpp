#include<iostream>
#include<string>
#include<sstream>

using namespace std;


int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

int lcm(int a, int b)
{
    return (a * b) / gcd(a, b);
}

int lcmArr(int arr[], int  Size) {
    int result = arr[0];
    for(int i = 0 ; i < Size ;i++)
        result = lcm( arr[i] , result );
    return result;
}

int main()
{
    int numCase, num ,result;
    string in;
    while( cin >> numCase >> ws ) {
        while( numCase-- ) {
            int* numArr = new int[999];
            getline(cin, in);
            istringstream ss(in);

            int count_num = 0;
            while( ss >> num ) {
                numArr[count_num] = num;
                count_num++;
            }
           result = lcmArr( numArr , count_num );
           cout << result << endl;
            delete [] numArr;
        }
    }

    return 0;
}
