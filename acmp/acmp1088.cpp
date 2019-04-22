#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")

#include <bits/stdc++.h>
using namespace std;
using ld = long double;
using ll = long long;
using ull = unsigned long long;

#define len(x) int((x).size())
#define all(x) (x).begin(), (x).end()

bool bishop(int x1, int y1, int x2, int y2)
{
    if (abs(x2 - x1) == abs(y2 - y1))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool rook(int x1, int y1, int x2, int y2)
{
    if ((x1 == x2 && y1 != y2) || (y1 == y2 && x1 != x2))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool knight(int x1, int y1, int x2, int y2)
{
    if (abs((x2-x1) * (y2-y1)) == 2)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool king(int x1, int y1, int x2, int y2)
{
    if (abs(x2 - x1) <= 1 && abs(y2 -y1) <= 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool pawn(int x1, int y1, int x2, int y2)
{
    if (x1 == x2 || y1 == 1)
    {
        if (y1 == 2 && (y1 + 1 == y2 || y1 + 2 == y2))
        {
            return true;
        }
        else if (y1 > 2 && (y1 + 1 == y2))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

bool queen(int x1, int y1, int x2, int y2)
{
    if (bishop(x1, y1, x2, y2) || rook(x1, y1, x2, y2))
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main() {
    string f_1, f_2;
    cin >> f_1 >> f_2;

    int x1 = f_1[0] - 'A' + 1;
    int y1 = f_1[1] - '0';

    int x2 = f_2[0] - 'A' + 1;
    int y2 = f_2[1] - '0';

    //printf("%d %d %d %d", x1, y1, x2, y2);

    bool ok = false;

    if (pawn(x1, y1, x2, y2))
    {
        ok = true;
        cout << "Pawn\n";
    }

    if (rook(x1, y1, x2, y2))
    {
        ok = true;
        cout << "Rook\n";
    }

    if (bishop(x1, y1, x2, y2))
    {
        ok = true;
        cout << "Bishop\n";
    }

    if (knight(x1, y1, x2, y2))
    {
        ok = true;
        cout << "Knight\n";
    }

    if (king(x1, y1, x2 ,y2))
    {
        ok = true;
        cout << "King\n";
    }

    if (queen(x1, y1, x2, y2))
    {
        ok = true;
        cout << "Queen\n";
    }

    if (!ok)
    {
        cout << "Nobody\n";
    }
}

/*
* (Actually read this pls)
    * Rlly bad errors: int overflow, array bounds
    * Less bad errors: special cases (n=1?), set tle
    * Common sense: do smth instead of nothing
*/
