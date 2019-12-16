#include<iostream>
#include<string>
#include<ctype.h>
using namespace std;

bool issymmetric(int **M, int RowSize ) {
    for(int i = 0; i < RowSize ; i++)
       for(int j = 0 ; j < RowSize ; j++)
            if(M[i][j] != M[j][i]) return false;

    return true;
}

int main() {
    int N;
    while( cin >> N ) {
        int** matrix = new int*[N];
        for(int i = 0 ; i < N ; i++)
            matrix[i] = new int[N];

        for(int i = 0; i < N ; i++)
            for(int j = 0 ; j < N ; j++)
                cin >> matrix[i][j];
            /*
        for(int i = 0, j = -1, k = 0 ; k < N * N ; k++) {
            cin >> matrix[i][++j];
            if( j == N-1 ) {
                i++; j = -1;
            }
        }*/

        if( issymmetric( matrix, N) )
            cout << "Yes!" << endl;
        else
            cout << "No!" << endl;

    }
    return 0;
}


/**
Sample Input
3
1 1 1
1 1 1
1 1 1
3
1 0 1
0 0 0
1 0 1
3
1 0 1
0 1 0
1 0 1
3
1 0 1
1 1 0
1 0 1

Sample Output
Yes!
Yes!
Yes!
No!
**/
