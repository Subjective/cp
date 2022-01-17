#include <bits/stdc++.h>

using namespace std;

const int mxP = 101;

int p, c;
bool adj[mxP][mxP];
bool vis[mxP];

void dfs(int v) {
    vis[v] = true;
    for (int u = 0; u < p; u++) {
        if (adj[v][u] && !vis[u]) {
            dfs(u);
        }
    }
}

void solve() {
    fill(&adj[0][0], &adj[0][0] + sizeof(adj), false);
    vector<pair<int, int>> connections;
    for (int i = 0; i < c; i++) {
        int a, b; cin >> a >> b;
        adj[a][b] = true;
        adj[b][a] = true;
        connections.push_back({ a, b });
    }
    for (auto connection : connections) {
        adj[connection.first][connection.second] = false;
        adj[connection.second][connection.first] = false;
        fill(vis, vis + p, false);
        dfs(0);
        for (int i = 0; i < p; i++) {
            if (!vis[i]) {
                cout << "Yes" << '\n';
                return;
            }
        }
        adj[connection.first][connection.second] = true;
        adj[connection.second][connection.first] = true;
    }
    cout << "No" << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while (cin >> p >> c && (p || c)) {
        solve();
    }
}
