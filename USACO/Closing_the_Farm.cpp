#include <bits/stdc++.h>

using namespace std;

const int mxN = 3e3 + 5;

int N, M;
vector<int> adj_list[mxN];
unordered_set<int> closed_farms;
bool vis[mxN];

bool closed(int farm) {
    return closed_farms.find(farm) != closed_farms.end();
}

void dfs(int u) {
    if (!closed(u)) {
        vis[u] = true;
        for (int v : adj_list[u]) {
            if (!vis[v] && !closed(v)) {
                dfs(v);
            }
        }
    }
}

int count_components() {
    fill(vis, vis + 1 + N, false);
    int count = 0;
    for (int i = 1; i <= N; i++) {
        if (!closed(i)) {
            if (!vis[i]) {
                count++;
                dfs(i);
            }
        }
    }
    return count;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    freopen("closing.in", "r", stdin);
    freopen("closing.out", "w", stdout);

    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    
    for (int i = 0; i < N; i++) {
        if (count_components() == 1) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
        int a; cin >> a;
        closed_farms.insert(a);
    }
}