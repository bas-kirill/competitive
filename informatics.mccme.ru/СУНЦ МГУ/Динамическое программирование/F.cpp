#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>
using namespace std;
using ld = long double;
using ll = long long;
using ull = unsigned long long;

#define len(x) int((x).size())
#define all(x) (x).begin(), (x).end()

int S, n, m;
vector<int> a, b;

void print_dp1(auto dp, int sum1)
{
    for (int i = 0; i <= sum1; i++) cout << setw(2) << i << ' '; cout << '\n';
    for (int i = 0; i < n; i++) { for (int j = 0; j <= sum1;j++) cout << setw(2) << dp[i][j] << " "; cout << '\n';}
    cout << "/------/" << '\n';
}

void print_dp2(auto dp, int sum2)
{
    for (int i = 0; i <= sum2; i++) cout << setw(2) << i << ' '; cout << '\n';
    for (int i = 0; i < m; i++) { for (int j = 0; j <= sum2;j++) cout << setw(2) << dp[i][j] << " "; cout << '\n';}
    cout << "/------/" << '\n';
}

int main() {
    //ifstream cin("in.txt");

    cin >> S;

    int sum1 = 0, sum2 = 0;

    cin >> n;
    a.resize(n);
    for (int &x : a)
    {
        cin >> x;
        sum1 += x;
    }

    cin >> m;
    b.resize(m);
    for (int &x : b)
    {
        cin >> x;
        sum2 += x;
    }

    vector<vector<bool>> dp_1(200, vector<bool>(100 * 100 + 1, false));

    for (int i = 0; i < n; i++)
    {
        dp_1[i][0] = true;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = sum1; j >= a[i]; --j)
        {
            if (dp_1[i][j - a[i]])
            {
                dp_1[i][j] = true;

                for (int k = i; k < n; k++)
                {
                    dp_1[k][j] = true;
                }
            }
        }
    }

    vector<vector<bool>> dp_2(200, vector<bool>(100 * 100 + 1, false));


    for (int i = 0; i < m; i++)
    {
        dp_2[i][0] = true;
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = sum2; j >= b[i]; --j)
        {
            if (dp_2[i][j - b[i]])
            {
                dp_2[i][j] = true;

                for (int k = i; k < m; k++)
                {
                    dp_2[k][j] = true;
                }
            }
        }
    }

    //print_dp1(dp_1, sum1);
    //print_dp2(dp_2, sum2);


    for(int j = sum1; j >= S; --j)
    {
        if (m == 0)
        {
            if (j == S)
            {
                int cur_sum2 = j - S;
                int cur_sum1 = j;
                //printf("%d, %d\n%d, %d\n%d, %d\n", j, j - S, cur_sum2, cur_sum1, sum1, sum2);
                //purchaser
                for (int i = n - 1; i >= 0; --i)
                {
                    if (i >= 1)
                    {
                        if (dp_1[i - 1][cur_sum1] == true)
                        {
                            continue;
                        }
                        else if (dp_1[i - 1][cur_sum1 - a[i]])
                        {
                            if (cur_sum1 == a[i])
                            {
                                cout << "+" << a[i] << " ";
                                break;
                            }
                            else
                            {
                                cout << "+" << a[i] << " ";
                                cur_sum1 -= a[i];
                            }
                        }
                    }
                    else
                    {
                        cout << "+" << a[i] << " ";
                    }
                }

                return 0;
            }
        }
        else if (dp_1[n - 1][j]== true && dp_2[m - 1][j - S] == true)
        {
            int cur_sum2 = j - S;
            int cur_sum1 = j;
            //printf("%d, %d\n%d, %d\n%d, %d\n", j, j - S, cur_sum2, cur_sum1, sum1, sum2);
            //purchaser
            for (int i = n - 1; i >= 0; --i)
            {
                if (i >= 1)
                {
                    if (dp_1[i - 1][cur_sum1] == true)
                    {
                        continue;
                    }
                    else if (dp_1[i - 1][cur_sum1 - a[i]])
                    {
                        if (cur_sum1 == a[i])
                        {
                            cout << "+" << a[i] << " ";
                            break;
                        }
                        else
                        {
                            cout << "+" << a[i] << " ";
                            cur_sum1 -= a[i];
                        }
                    }
                }
                else
                {
                    cout << "+" << a[i] << " ";
                }
            }

            if (cur_sum2 != 0)
            {
                //seller
                for (int i = m - 1; i >= 0; --i)
                {
                    if (i >= 1)
                    {
                        if (dp_2[i - 1][cur_sum2] == true)
                        {
                            continue;
                        }
                        else if (dp_2[i - 1][cur_sum2 - b[i]])
                        {
                            if (cur_sum2 - b[i] == 0)
                            {
                                cout << -b[i] << " ";
                                break;
                            }
                            else
                            {
                                cout << -b[i] << " ";
                                cur_sum2 -= b[i];
                            }
                        }
                    }
                    else
                    {
                        cout << -b[i] << " ";
                        return 0;
                    }
                }
            }

            return 0;
        }
    }

    cout << "Impossible";
}

/*
* (Actually read this pls)
    * Rlly bad errors: int overflow, array bounds
    * Less bad errors: special cases (n=1?), set tle
    * Common sense: do smth instead of nothing
*/
