#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int INF = 2.1e9;
int N = 8350;
struct edge {
    int u, v, w;
    edge() : u(0), v(0), w(0) {}
    edge(int u, int v, int w) : u(u), v(v), w(w) {}
};

vector<int> dist;

void init() {
    freopen("output2.txt", "w", stdout);
}

bool read() {
    if (N <= 10000) return true;
    return false;
}

void solve() {
    vector<edge> v;
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            v.push_back(edge{i, j, ((179 * (i+1) + 719 * (j+1)) % 1000 - 500)});
        }
    }

    dist.assign(N, INF);
    dist[0] = 0;
    bool flag = 0;
    for (int i = 0; i < N; ++i) {
        flag = 0;
        for (int j = 0; j < v.size(); ++j) {
            if (dist[v[j].v] > dist[v[j].u] + v[j].w) {
                dist[v[j].v] = max(dist[v[j].u] + v[j].w, -INF);
                flag = 1;
            }
        }
        if (!flag) break;
    }

    cout << dist[N - 1] << ", ";
}

int main() {
    init();
    while (read()) {
        solve();
        ++N;
    }
}
