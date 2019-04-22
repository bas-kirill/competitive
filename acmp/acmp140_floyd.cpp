#include <bits/stdc++.h>
using namespace std;

int N;
int a[100][100];
int w[100][100];
int w1[100][100];
const int INF = 2.1e9;

int main() {
    freopen("input.txt", "r", stdin);
    cin >> N;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j) {
            cin >> a[i][j];
            if (a[i][j] == 1e5)
                a[i][j] = INF;
        }

    memcpy(w, a, sizeof a);
    for (int k = 0; k < N; ++k)
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                if (w[i][k] < INF && w[k][j] < INF)
                    w[i][j] = min(w[i][j], w[i][k] + w[k][j]);
    memcpy(w1, w, sizeof w);
    for (int k = 0; k < N; ++k)
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                if (w1[i][k] < INF && w1[k][j] < INF)
                    w1[i][j] = min(w1[i][j], w1[i][k] + w[k][j]);

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            if (w[i][j] != w1[i][j])
                return puts("YES"), 0;
    puts("NO");
}
