#include <bits/stdc++.h>

using namespace std;

const int mxN = 1e5 + 10;

int n, m;
vector<int> adj[mxN];
int color[mxN];

void dfs(int u, int c = 1) {
    color[u] = c;
    for (auto &v : adj[u]) {
        if (!color[v]) {
            dfs(v, 3 - c);
        } else if (color[v] == c) {
            cout << "IMPOSSIBLE\n";
            exit(0);
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        if (!color[i]) {
            dfs(i);
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << color[i] << ' ';
    }
    cout << '\n'; 
}