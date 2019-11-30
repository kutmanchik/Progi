#include <iostream>
#include <cstdio>
using namespace std;
int main(){
    int n,i, j;
    int nr, nc, ri, ci, sum = 0;
    int mat[100][100];
    while(cin >> n)
        {
        if(n == 0)
            break;
        nc=nr = 0;
    //read 2d array
        for(i = 0; i < n; i++){
            for(j = 0; j < n; j++){
                cin >> mat[i][j];
            }
        }
    //
        for(i = 0; i < n; i++)
        {
            sum = 0;
            for(j = 0; j < n; j++){
                sum += mat[i][j];
            }
            if(sum % 2 == 1){
                nr++;
                ri = i;
            }
        }
        for(j = 0; j < n; j++){
            sum = 0;
            for(i = 0; i < n; i++){
                sum += mat[i][j];
            }
            if(sum % 2 == 1){
                nc++;
                ci = j;
            }
        }
        if(nc > 1 || nr > 1){
            cout << "Corrupt" << endl;
            continue;
        }
        if(nc== 0 && nr == 0){
            cout << "OK" << endl;
            continue;
        }
        cout<<"Change bit ("<<ri+1<<","<<ci+1<<")"<<endl;
    }
    return 0;
}
