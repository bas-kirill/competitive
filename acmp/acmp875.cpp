#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/STACK:16777216")

#include <bits/stdc++.h>
using namespace std;
using ld = long double;
using ll = long long;
using ull = unsigned long long;

#define len(x) int((x).size())
#define all(x) (x).begin(), (x).end()

int n, m, K;

pair<int, int> get(int x, int y)
{
    return {(x + m) % m, (y + n) % n};
}

int main() {

    cin >> n >> m >> K;

    vector<vector<char>> t(n, vector<char>(m));

    for (auto &x : t)
    {
        for (auto &y : x)
        {
            cin >> y;
        }
    }

//    cout << get(-1, -1).first << " " << get(-1, -1).second << endl;


//    for (auto &x : t)
//    {
//        for (auto &y : x)
//        {
//            cout << y << " ";
//        }
//        cout << '\n';
//    }

    for (int k = 0; k < K; k++)
    {
        vector<vector<char>> tmp_t(n, vector<char>(m));
        tmp_t = t;
        //dead cells
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (t[i][j] == '.')
                {
                    int alive = 0;
                    for (int i_l = i-1; i_l <= i+1; i_l++)
                    {
                        for (int j_l = j-1; j_l <= j + 1; j_l++)
                        {
                            if (i_l == i && j_l == j)
                            {
                                continue;
                            }
                            auto p = get(j_l, i_l);
                            if (t[p.second][p.first] == '*')
                            {
                                printf("[%d, %d]\n", p.second, p.first);
                                ++alive;
                            }
                        }
                    }

                    printf("i: %d, j: %d, alive: %d\n", i, j, alive);

                    if (alive == 3)
                    {
                        tmp_t[i][j] = '*';
                    }
                }
            }
        }

        //alive cells

        vector<vector<char>> tmp_t1(n, vector<char>(m));
        tmp_t1 = t;
        //dead cells
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (tmp_t[i][j] == '*')
                {
                    int alive = 0;
                    for (int i_l = i-1; i_l <= i+1; i_l++)
                    {
                        for (int j_l = j-1; j_l <= j + 1; j_l++)
                        {
                            if (i_l == i && j_l == j)
                            {
                                continue;
                            }
                            auto p = get(j_l, i_l);
                            if (tmp_t[p.second][p.first] == '*')
                            {
                                printf("[%d, %d]\n", p.second, p.first);
                                ++alive;
                            }
                        }
                    }

                    printf("i: %d, j: %d, alive: %d\n", i, j, alive);

                    if (alive == 3 || alive == 2)
                    {
                        tmp_t1[i][j] = '*';
                    }
                    else
                    {
                        tmp_t1[i][j] = '.';
                    }
                }
            }
        }

        t = tmp_t1;
    }

    for (auto x : t)
    {
        for (auto y : x)
        {
            cout << y;
        }
        cout << '\n';
    }
}

/*
* (Actually read this pls)
    * Rlly bad errors: int overflow, array bounds
    * Less bad errors: special cases (n=1?), set tle
    * Common sense: do smth instead of nothing
*/
