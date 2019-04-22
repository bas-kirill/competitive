#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma comment(linker, "/STACK:16777216")

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define len(x) int((x).size())
#define all(x) (x).begin(), (x).end()

char lower(char c)
{
    if (c >= 'A' && c <= 'Z')
    {
        return (c + 32);
    }
    else if (c >= 'a' && c <= 'z')
    {
        return c;
    }
}

int main() {
    string s, s1;
    cin >> s >> s1;

    /*if (s == s1)
    {
        cout << s;
        return 0;
    }*/

    if (s1 < s)
    {
        swap(s, s1);
    }

    int n = len(s);
    int m = len(s1);

    string lower_s(s), lower_s1(s1);
    for (char &c : lower_s)
    {
        c = lower(c);
    }
    for (char &c : lower_s1)
    {
        c = lower(c);
    }

    set<string> ans;

    for (int i = n-1; i >= 0; --i)
    {
        //cout << lower_s.substr(i, n-i) << " " << lower_s1.substr(0, n-i) << endl;
        if (lower_s.substr(i, n-i) == lower_s1.substr(0, n-i))
        {
            string cur_ans = s.substr(0, i) + s1;
            /*if (len(cur_ans) < ans_len)
            {
                ans_len = len(cur_ans);
                ans_s = cur_ans;
            }*/
            ans.insert(cur_ans);
        }
    }

    swap(s, s1);

    for (int i = n-1; i >= 0; --i)
    {
        //cout << lower_s.substr(i, n-i) << " " << lower_s1.substr(0, n-i) << endl;
        if (lower_s.substr(i, n-i) == lower_s1.substr(0, n-i))
        {
            string cur_ans = s.substr(0, i) + s1;
            /*if (len(cur_ans) < ans_len)
            {
                ans_len = len(cur_ans);
                ans_s = cur_ans;
            }*/
            ans.insert(cur_ans);
        }
    }

    /*for (auto it : ans)
    {
        cout << it << endl;
    }*/

    cout << (len(ans) == 0 ? (s < s1 ? s + s1 : s1 + s) : (*ans.begin()));

    //cout << lower_s << " " << lower_s1;
}

/*
* (Actually read this pls)
    * Rlly bad errors: int overflow, array bounds
    * Less bad errors: special cases (n=1?), set tle
    * Common sense: do smth instead of nothing
*/
