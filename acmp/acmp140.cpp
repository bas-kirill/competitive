#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N;
ll a[100][100];
const ll INF = 1e18;
struct edge {
    ll u, v, w;
    edge() : u(0), v(0), w(0) {}
    edge(ll u, ll v, ll w) : u(u), v(v), w(w) {}
};
vector<edge> v;

signed main() {
   // freopen("input.txt", "r", stdin);
    cin >> N;
    for (ll i = 0; i < N; ++i) {
        for (ll j = 0; j < N; ++j) {
            cin >> a[i][j];
            if (a[i][j] != 0 && a[i][j] != 1e5)
                v.push_back(edge{i, j, a[i][j]});
        }
    }

    for (ll i = 0; i < N; ++i) if (a[i][i] < 0) return puts("YES"), 0;

    vector<ll> dist(N, INF);
    dist[0] = 0;
    bool flag = 0;
    for (ll i = 0; i < N; ++i) {
        flag = 0;
        for (ll j = 0; j < v.size(); ++j) {
            if (dist[v[j].v] > dist[v[j].u] + v[j].w) {
                dist[v[j].v] = dist[v[j].u] + v[j].w;
                flag = 1;
            }
        }
    }

    cout << (flag ? "YES" : "NO");
}
