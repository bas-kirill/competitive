#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
using ld = long double;
using ll = long long;
using ull = unsigned long long;

#define len(x) int((x).size())
#define all(x) (x).begin(), (x).end()

int main()
{
    int ans = 0;
    int sign = 1;
    char c;
    int num[10];
    for (int i = 0; i < 10; i++) num[i] = 0;
    int tmp = 9;
    while ((c = cin.get()) != '.')
    {
        if (isdigit(c))
            num[tmp--] = c - '0';
        else
        {
            int tmp_ans = 0;
            for (int i = tmp + 1; i < 10; i++) tmp_ans += sign * (num[i] * pow(10, abs(i - tmp - 1)));
            ans += tmp_ans;
            //cout << tmp_ans << endl;
            if (c == '-')
                sign = -1;
            else
                sign = 1;
            tmp = 9;
        }
    }
    int tmp_ans = 0;
    for (int i = tmp + 1; i < 10; i++) tmp_ans += sign * (num[i] * pow(10, abs(i - tmp - 1)));
    //cout << tmp_ans << endl;
    ans += tmp_ans;
    cout << ans << '\n';
}

/*
* (Actually read this pls)
    * Rlly bad errors: int overflow, array bounds
    * Less bad errors: special cases (n=1?), set tle
    * Common sense: do smth instead of nothing
*/
