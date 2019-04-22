#include <bits/stdc++.h>
using namespace std;

int main(){
    int X1, Y1, X2, Y2;
    cin >> X1 >> Y1 >> X2 >> Y2;

    if (X1 == X2 && Y1 != Y2) //vertical
    {
        cout << "YES";
        return 0;
    }
    else if (Y1 == Y2 && X1 != X2) //horizontal
    {
        cout << "YES";
        return 0;
    }
    else if (abs(X1 - X2) == abs(Y1 - Y2))
    {
        cout << "YES";
        return 0;
    }
    else
    {
        cout << "NO";
    }
}
