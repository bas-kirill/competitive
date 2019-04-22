#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define len(x) int((x).size())
#define all(x) (x).begin(), (x).end()

struct bor
{
    struct node
    {
        int next[26];
        bool isTerminal;
    };

    node make_node()
    {
        node v;
        for (int i = 0; i < 26; i++)
        {
            v.next[i] = -1;
        }
        v.isTerminal = false;
        return v;
    }

    vector<node> v_bor;

    bor()
    {
        v_bor.push_back(make_node());
    }

    int cnt = 0;

    void add(string s)
    {
        int v = 0;
        for (int i = 0; i < len(s); i++)
        {
            char c = s[i] - 'a';
            if (v_bor[v].next[c] == -1)
            {
                v_bor.push_back(make_node());
                v_bor[v].next[c] = len(v_bor) - 1;
            }
            v = v_bor[v].next[c];
        }
        if (!v_bor[v].isTerminal)
        {
            cnt++;
            v_bor[v].isTerminal = true;
        }
    }

    bool find(string s)
    {
        int v = 0;
        for (int i = 0; i < len(s); i++)
        {
            char c = s[i] - 'a';
            if (v_bor[v].next[c] == -1)
            {
                return false;
            }
            else
            {
                v = v_bor[v].next[c];
            }
        }
        if (v_bor[v].isTerminal)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main() {
    bor b;
    b.add("ace");
    b.add("hello");
    b.add("hell");
    b.add("hell");
    //cout << b.find("hello")<< endl;
    //b.add("hell");
    cout << b.find("ace") << endl;
    cout << b.find("hello") << endl;
    cout << b.find("hell") << endl;
    cout << b.find("NaS") << '\n';
    cout << b.cnt << endl;
}

/*
* (Actually read this pls)
    * Rlly bad errors: int overflow, array bounds
    * Less bad errors: special cases (n=1?), set tle
    * Common sense: do smth instead of nothing
*/
