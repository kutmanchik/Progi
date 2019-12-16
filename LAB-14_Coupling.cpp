#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

int count_couple( char *str ) {
    int num_couple = 0;
    vector<char> couple_char;

    for(int i = 0; i < strlen(str) ; i++) {
        if( str[i] == '.' ) continue;
        couple_char.push_back(str[i]);
    }

    for(int i = 0 ; i < couple_char.size() ; i++) {
        if(couple_char[i] != 'B') continue;
        for(int j = i ; j < couple_char.size() ; j++) {
            if(couple_char[j] == 'G') {
                couple_char[i] = '#';
                couple_char[j] = '#';
                num_couple++;
                break;
            }
        }
    }

    return num_couple;
}

int main() {
    int n;
    cin >> n >> ws;

    while(n--) {
        char str[256];
        cin.getline(str, 256);
        cout << count_couple( str ) << endl;
    }

    return 0;
}

/**

Sample Input
2
..B..B.B...G.G
.B...GG..B..BG.B..G.GBB..GBG

Sample Output
2
6
*/
