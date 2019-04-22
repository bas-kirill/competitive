#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma comment(linker, "/STACK:16777216")

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define len(x) int((x).size())
#define all(x) (x).begin(), (x).end()

int f(int x, int y, int x1, int y1, int lev=0)
{
    if (lev == 0)
    {
        if (abs((x1 - x) * (y1 - y)) == 2)
        {
            return 1;
        }
        else
        {
            int v1 = f(x+1, y+2, x1, y1, lev=1);
            int v2 = f(x+2, y+1, x1, y1, lev=1);
            int v3 = f(x+2, y-1, x1, y1, lev=1);
            int v4 = f(x+1, y-2, x1, y1, lev=1);
            int v5 = f(x-1, y-2, x1, y1, lev=1);
            int v6 = f(x-2, y-1, x1, y1, lev=1);
            int v7 = f(x-2, y+1, x1, y1, lev=1);
            int v8 = f(x-1, y+2, x1, y1, lev=1);
            //cout << v1 << " " << v2 << " " << v3 << " " << v4 << " " << v5 << " " << v6 << " " << v7 << " " << v8 << endl;
            if (v1 + v2 + v3 + v4 + v5 + v6 + v7 + v8 > 0)
            {
                return 2;
            }
            else
            {
                return 0;
            }
        }
    }
    else if (lev == 1)
    {
        if (x <= 0 || y <= 0 || x1 > 8 || y1 > 8)
        {
            return 0;
        }
        else if (abs((x1 - x) * (y1 - y)) == 2)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}

int f1(int x, int y, int x1, int y1, int lev=0)
{
    if (lev == 0)
    {
        if (abs((x1 - x) * (y1 - y)) == 2)
        {
            return 1;
        }
        else
        {
            int v1 = f1(x+1, y+2, x1, y1, lev+1);
            int v2 = f1(x+2, y+1, x1, y1, lev+1);
            int v3 = f1(x+2, y-1, x1, y1, lev+1);
            int v4 = f1(x+1, y-2, x1, y1, lev+1);
            int v5 = f1(x-1, y-2, x1, y1, lev+1);
            int v6 = f1(x-2, y-1, x1, y1, lev+1);
            int v7 = f1(x-2, y+1, x1, y1, lev+1);
            int v8 = f1(x-1, y+2, x1, y1, lev+1);
        }
    }
    else
    {
        if (x <= 0 || y <= 0 || x > 8 || y > 8)
        {
            return 0;
        }
        else if (x == x1 && y == y1 && lev == 2)
        {
            return 2;
        }
        else
        {
            return 0;
        }
    }
}

int main() {
    string s, s1;
    cin >> s >> s1;
    int X1, Y1, X2, Y2;
    X1 = s[0] - 'a' + 1;
    Y1 = s[1] - '0';
    X2 = s1[0] - 'a' + 1;
    Y2 = s1[1] - '0';

    //cout << X1 << " " << Y1 << " " << X2 << " " << Y2;


    int ans = f(X1, Y1, X2, Y2);
    if (ans == 0)
    {
        cout << "NO";
    }
    else if (ans == 1)
    {
        cout << 1;
    }
    else if (ans == 2)
    {
        cout << 2;
    }
}

/*
* (Actually read this pls)
    * Rlly bad errors: int overflow, array bounds
    * Less bad errors: special cases (n=1?), set tle
    * Common sense: do smth instead of nothing
*/
