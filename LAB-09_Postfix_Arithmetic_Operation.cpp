#include <iostream>
#include <string>


using namespace std;

int postfix_cal(int n1, int n2, char op)  {
    switch(op) {
        case '+' : return n1 + n2;
        case '-' : return n1 - n2;
        case '*' : return n1 * n2;
        case '/' : return n1 / n2;
    }
}

int main()
{
    string Token;

    while( getline(cin, Token) ) {
        int*  Stack    = new int[ Token.size() ];
        int top = -1, temp;
        for(int i = 0 ; i < Token.size(); i++) {
            if( isdigit(Token[i]) ) {
                Stack[++top] = Token[i] - '0';
            }
            else {
                temp = postfix_cal( Stack[top-1] , Stack[top]  , Token[i] );
                Stack[--top] = temp;
                if( top == -1 ) break;
            }
        }
        if( top == 0 ) cout << Stack[top] << endl;
        else cout << "Input Error" << endl;
    }
    return 0;
}

/*
Sample Input
35+
3+5
63/14-*3+8-

Sample Output
8
Input Error
-11
*/
