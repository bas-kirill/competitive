#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma comment(linker, "/STACK:16777216")

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll BITS = 30;

#define len(x) int((x).size())
#define all(x) (x).begin(), (x).end()

int main() {
    freopen("in.txt", "r", stdin);
    cin.tie();
    ios_base::sync_with_stdio(NULL);
    ll n, W;
    cin >> n >> W;
    vector<int> w(n), p(n);
    for (int i = 0; i < n; i++)
    {
        cin >> w[i] >> p[i];
    }
    ll ans_p = 0;
    bitset<31> items;
    for (int i = 1; i < (1 << n); i++)
    {
        ll cur_w = 0;
        ll cur_p = 0;
        bitset<31> cur_items;
        for (ll shift = BITS; shift >= 0; --shift)
        {
            if (i & (1 << shift))
            {
                cur_w += w[shift];
                cur_p += p[shift];
                cur_items.set(shift);
            }
            //cout << ((i & (1 << shift)) > 0 ? 1 : 0);
        }
        //for (int i = 30; i >= 0; --i) cout << cur_items.test(i); cout << endl;
        //cout <<" " << cur_w << " " << cur_p << " " << endl;

        if (cur_w <= W)
        {
            if (cur_p > ans_p)
            {
                ans_p = cur_p;
                items = cur_items;
            }
            else if (cur_p == ans_p)
            {
                if (cur_items.count() < items.count())
                {
                    items = cur_items;
                }
                else if (cur_items.count() == items.count())
                {
                    //for (int i = 0; i < 31; i++) cout << cur_items.test(i) << " "; cout << endl;
                    vector<int> to_num1, to_num2;
                    for (int i = 0; i < 31; i++)
                    {
                        if (items.test(i))
                        {
                            to_num1.push_back(i);
                        }
                        if (cur_items.test(i))
                        {
                            to_num2.push_back(i);
                        }
                    }

                    for (int i = 0; i < len(to_num1); i++)
                    {
                        if (to_num2[i] < to_num1[i])
                        {
                            items = cur_items;
                            break;
                        }
                    }
                }
            }
        }

        //cout << endl;
    }

    cout << items.count() << ' ' << ans_p << endl;
    for (int i = 0; i < 31; i++)
    {
        if (items.test(i))
        {
            cout << i + 1 << " ";
        }
    }
}

/*
* (Actually read this pls)
    * Rlly bad errors: int overflow, array bounds
    * Less bad errors: special cases (n=1?), set tle
    * Common sense: do smth instead of nothing
*/
