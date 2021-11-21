#include <bits/stdc++.h>

using namespace std;

const int mxN = 1e5;

int n, m, rep[mxN];
vector<int> adj_list[mxN];
bool vis[mxN];

void dfs(int u) {
    vis[u] = 1;
    for (int v : adj_list[u]) {
        if (!vis[v]) {
            dfs(v);
        }
    } 
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            rep[count++] = i + 1;
            dfs(i);
        }
    }
    cout << count - 1 << '\n'; 
    for (int i = 1; i < count; i++) {
        cout << rep[i - 1] << ' ' << rep[i] << '\n';
    }
}