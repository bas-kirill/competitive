//2xTopsort + delete '='

#include <bits/stdc++.h>
using namespace std;

#define vector<int> vi

int N, M, V;
vector<vector<int, char>> g;

int main() {
    freopen("input.txt", "r", stdin);
    cin >> N >> M >> V;
    for (int i = 0; i < V; ++i) {
        string s; cin >> s;
        int u, v;
        int ind = -1;
        for (int j = 0; j < s.size(); ++j) {
            if (s[j] == '<' || s[j] == '>' || s[j] == '=') {
                ind = j;
            }
        }

        string u_s = s.substr(0, ind), v_s = s.substr(ind + 1, s.size() - ind);
        u = atoi(u_s.c_str()); v = atoi(v_s.c_str());
//        cout << u << " " << v << '\n';
        if (s[ind] == '<')
            g[u].push_back({v, '<'});
        else if (s[ind] == '>')
            g[v].push_back({u, '>'});
        else {
            g[u].push_back({v, '='});
            g[v].push_back({u, '='});
        }
    }

    for (int i = 0; i < g.size(); ++i) {
        for (int j = 0; j < g[i].size(); ++j)
    }
}
