#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/STACK:16777216")

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define len(x) int((x).size())
#define all(x) (x).begin(), (x).end()

int main() {
    string s_queen, s_rook, s_horse;
    cin >> s_queen >> s_rook >> s_horse;

    vector<vector<bool> > table(9, vector<bool>(9, false));

    int x_q = s_queen[0] - 'A' + 1;
    int y_q = s_queen[1] - '0';
    int x_r = s_rook[0] - 'A' + 1;
    int y_r = s_rook[1] - '0';
    int x_h = s_horse[0] - 'A' + 1;
    int y_h = s_horse[1] - '0';

    table[y_q][x_q] = true;
    table[y_r][x_r] = true;
    table[y_h][x_h] = true;

    for (int y = 8; y >= 1; --y)
    {
        for (int x = 1; x <= 8; x++)
        {
            if (abs((x_h - x) * (y_h - y)) == 2)
            {
                table[y][x] = true;
            }
            else if ((x_r - x) * (y_r  - y) == 0)
            {
                table[y][x] = true;
            }
            else if (abs(x_q - x) == abs(y_q - y))
            {
                table[y][x] = true;
            }
            else if ((x_q - x) * (y_q - y) == 0)
            {
                table[y][x] = true;
            }
        }
    }

    int ans = 0;
    for (int i = 8; i >= 1; --i)
    {
        for (int j = 1; j <= 8; j++)
        {
            ans += (table[i][j] ? 1 : 0);
            //cout << (table[i][j] ? '+' : '-');
        }
        cout << endl;
    }

    cout << ans - 3;
}

/*
* (Actually read this pls)
    * Rlly bad errors: int overflow, array bounds
    * Less bad errors: special cases (n=1?), set tle
    * Common sense: do smth instead of nothing
*/
