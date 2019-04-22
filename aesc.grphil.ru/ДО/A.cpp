#include <bits/stdc++.h>
using namespace std;

#define len(x) int((x).size())
#define all(x) (x).begin(), (x).end()

const int maxn = 4 * 100000;

int n;
char a[maxn];
int tree[4 * maxn];

struct node {
    char color;
};

int main() {
    ifstream cin("in.txt");
    cin >> n;



    for (int i = 0; i < n; i++)
    {
        char c;
        int l, r;
        cin >> c >> l >> r;
    }
}

/*
* (Actually read this pls)
    * Rlly bad errors: int overflow, array bounds
    * Less bad errors: special cases (n=1?), set tle
    * Common sense: do smth instead of nothing
*/
