#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma comment(linker, "/STACK:16777216")

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define len(x) int((x).size())
#define all(x) (x).begin(), (x).end()

int ans = 0;
int n, m;

set<vector<int> > s;

void f(bitset<1000> trees, int j=-1)
{
    if (j != -1)
    {
        trees.reset(j);
    }

    if (trees.count() == m)
    {
        vector<int> numbers;
        for (int i = 0; i < n; i++)
        {
            if (trees.test(i))
            {
                numbers.push_back(i);
            }
        }

        bool ok = true;
        int shift = -1;
        for (int i = 1; i < len(numbers); i++)
        {
            if (shift == -1)
            {
                shift = numbers[i] - numbers[i-1];
            }
            else
            {
                if (numbers[i] - numbers[i-1] != shift)
                {
                    ok = false;
                }
            }
        }

        if (ok)
        {
//            for (int x : numbers)
//        {
//            cout << x << " ";
//        }
        cout << endl;
            s.insert(numbers);
            ++ans;
        }
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            if (trees.test(i))
            {
                //cout << "i: " << i << endl;
                f(trees, i);
            }
        }
    }
}

int main() {
    cin >> n >> m;

    if (m > n)
    {
        cout << 0;
        return 0;
    }
    else if (n == m)
    {
        cout << 1;
        return 0;
    }

    bitset<1000> trees;
    for (int i = 0; i < n; i++)
    {
        trees[i] = true;
    }


    f(trees);

    cout << len(s);
}

/*
* (Actually read this pls)
    * Rlly bad errors: int overflow, array bounds
    * Less bad errors: special cases (n=1?), set tle
    * Common sense: do smth instead of nothing
*/
