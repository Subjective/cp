#include <bits/stdc++.h>

using namespace std;

const int mxN = 1e5 + 10;

int N, M;
vector<int> adj[mxN];
pair<int, int> coords[mxN];
bool visited[mxN];

int minX, maxX, minY, maxY;

void dfs(int v) {
    visited[v] = true;

    minX = min(minX, coords[v].first);
    maxX = max(maxX, coords[v].first);
    minY = min(minY, coords[v].second);
    maxY = max(maxY, coords[v].second);

    for (int u : adj[v]) {
        if (!visited[u]) {
            dfs(u);
        }
    }
}

int solve() {
    int ans = INT_MAX;
    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            minX = INT_MAX, maxX = INT_MIN, minY = INT_MAX, maxY = INT_MIN;
            dfs(i);
            ans = min(ans, 2 * (maxX - minX + maxY - minY));
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("fenceplan.in", "r", stdin);
    freopen("fenceplan.out", "w", stdout);

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        int x, y; cin >> x >> y;
        coords[i] = { x, y };
    }
    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    cout << solve() << '\n';
}