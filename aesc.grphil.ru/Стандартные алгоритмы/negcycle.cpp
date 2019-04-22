#include <bits/stdc++.h>
using namespace std;
#define int long long
int N, M;
int a[100][100];
const int INF = 1e18;
struct edge { int u, v, w; };
vector<edge> v;

signed main() {
    freopen("negcycle.in", "r", stdin);
    freopen("negcycle.out", "w", stdout);
    cin >> N;
    M = 0;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)  {
            cin >> a[i][j];
            if (a[i][j] != 0 && a[i][j] != 1e5)
                v.push_back({i, j, a[i][j]});
        }

    vector<int> dist(N, INF), p(N, -1);
    dist[0] = 0;
    int x = -1;
    for (int i = 0; i < N; ++i) {
        x = -1;
        for (int j = 0; j < v.size(); ++j) {
            if (dist[v[j].u] < INF) {
                if (dist[v[j].v] > dist[v[j].u] + v[j].w) {
                    dist[v[j].v] = dist[v[j].u] + v[j].w;
                    p[v[j].v] = v[j].u;
                    x = v[j].v;
                }
            }
        }
        if (x == -1)
            break;
    }

    //DEBUG
//    cout << "BEGIN" << endl;
//    for (int x : dist) cout << x << " "; cout << endl;
//    for (int x : p) cout << x << " "; cout << endl;
//    for (edge x : v) printf("%d %d %d\n", x.u, x.v, x.w);
//    cout << "END" << endl;
    //DEBUG

    if (x == -1) return puts("NO"), 0;

    int cx = x;
    for (int i = 0; i < 1488; ++i) cx = p[cx];
    int ccx = p[cx];
    vector<int> cycle = {cx};
    while (ccx != cx) {
        cycle.push_back(ccx);
        ccx = p[ccx];
    }
    cout << "YES\n";
    reverse(cycle.begin(), cycle.end());
    printf("%d\n", cycle.size());
    for (int x : cycle) printf("%d ", x+1);
    //fclose(stdin);
}
