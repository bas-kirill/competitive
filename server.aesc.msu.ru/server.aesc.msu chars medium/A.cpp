#include <bits/stdc++.h>
using namespace std;

#define len(x) int((x).size())
#define all(x) (x).begin(), (x).end()

int main() {
    char c_1, c_2;
    cin >> c_1 >> c_2;


    if (c_1 != 'A' || c_2 != 'B')
        return cout << "NO", 0;


    bool fl = 0;
    for (int i = 0; i < 3; i++) {
        cin >> c_1;


        if (i == 0)
        {
            if (c_1 == 'C') continue;
            else if (fl && c_1 == 'X')
            {
                cin >> c_1;
                if (c_1 == '.')
                    return cout << "YES", 0;
            }
            else return cout << "NO", 0;
        }
        else if (i == 1)
        {
            if (c_1 == 'E')
            {
                i = -1, fl = 1;
                continue;
            }
            else if (c_1 == 'D') continue;
            else return cout << "NO", 0;
        }
        else if (i == 2)
        {
            if (c_1 == 'F')
            {
                i = -1, fl = 1;
                continue;
            }
            else return cout << "NO", 0;
        }
    }
}

/*
* (Actually read this pls)
    * Rlly bad errors: int overflow, array bounds
    * Less bad errors: special cases (n=1?), set tle
    * Common sense: do smth instead of nothing
*/
