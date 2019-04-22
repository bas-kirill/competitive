//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma comment(linker, "/STACK:16777216")

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

    void add(const string &s)
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

    bool find(const string &s)
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

    void del(const string &s)
    {
        bool exist = find(s);

        if (!exist)
        {
            return;
        }
        else
        {
            int v = 0;
            for (int i = 0; i < len(s); i++)
            {
                char c = s[i] - 'a';
                if (v_bor[v].next[c] != -1)
                {
                    v_bor[v].next[c] = -1;
                    v = v_bor[v].next[c];
                }
            }
            if (v_bor[v].isTerminal)
            {
                v_bor[v].isTerminal = false;
                --cnt;
            }
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    bor b;
    char flag;
    string word;
    while (true)
    {
        cin >> flag;

        if (flag == '#')
        {
            return 0;
        }
        else
        {
            cin >> word;
        }

        if (flag == '+')
        {
            b.add(word);
        }
        else if (flag == '-')
        {
            b.del(word);
        }
        else if (flag == '?')
        {
            cout << (b.find(word) ? "YES" : "NO") << endl;
        }
    }
}

/*
* (Actually read this pls)
    * Rlly bad errors: int overflow, array bounds
    * Less bad errors: special cases (n=1?), set tle
    * Common sense: do smth instead of nothing
*/
