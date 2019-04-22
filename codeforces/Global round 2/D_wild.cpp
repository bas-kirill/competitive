#include <bits/stdc++.h>
using namespace std;

int n, k;
long long a[100005], b[100005], sum[100005], l, r, ans, cnt;
struct Node {
    long long l, r, ans;
    int id;
};

Node e[100005];
inline long long min(long long x, long long y) {
    return x < y ? x : y;
}

bool cmp(long long x, long long y) {
    return x > y;
}

bool cmp2(Node x, Node y) {
    return x.r - x.l > y.r - y.l;
}

bool cmp3(Node x, Node y) {
    return x.id < y.id;
}

int main() {
    ifstream cin("output.txt");
    cin >> n;
    a[n + 1] = 9223372036854775807;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i) {
        b[i] = a[i + 1] - a[i];
    }
    sort(b + 1, b + n + 1, cmp);
    for (int i = 1; i <= n; ++i) {
        sum[i] = sum[i - 1] + b[i];
    }
    cin >> k;
    for (int i = 1; i <= k; ++i) {
        cin >> e[i].l >> e[i].r;
        e[i].id = i;
    }
    sort(e + 1, e + k + 1, cmp2);
    for (int i = 1; i <= k; ++i) {
        for (int j = cnt + 1; j <= n; ++j) {
            if (b[j]>=e[i].r-e[i].l + 1) cnt++;
            else break;
        }
        e[i].ans = (e[i].r - e[i].l + 1) * cnt + sum[n] - sum[cnt];
    }

    sort(e + 1, e + k + 1, cmp3);
    for (int i = 1; i <= k; ++i)
        cout << e[i].ans << endl;
}
