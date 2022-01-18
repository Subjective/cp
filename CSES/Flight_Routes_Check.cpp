#include <bits/stdc++.h>

using namespace std;

const int mxN = 1e5 + 10;

int n, m, rep[mxN];
vector<int> adj[mxN][2];
bool vis[mxN];

void dfs(int v, int x) {
    vis[v] = true;
    for (int u : adj[v][x]) {
        if (!vis[u]) {
            dfs(u, x);
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[a][0].push_back(b);
        adj[b][1].push_back(a);
    }
    dfs(1, 0);
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            cout << "NO\n" << 1 << ' ' << i << '\n';
            return 0;
        }
    }
    fill(vis, vis + mxN, false);
    dfs(1, 1);
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            cout << "NO\n" << i << ' ' << 1 << '\n';
            return 0;
        }
    }
    cout << "YES\n";
}