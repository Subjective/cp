#include <bits/stdc++.h>

using namespace std;

int N;
pair<pair<int, int>, int> cows[200];
vector<int> adj_list[200];
bool visited[200];

int dist(pair<int, int> p1, pair<int, int> p2) {
    return pow(p2.first - p1.first, 2) + pow(p2.second - p1.second, 2);
}

int dfs(int v) {
    int count = 1;
    visited[v] = true;
    for (int u : adj_list[v]) {
        if (!visited[u]) {
            count += dfs(u);
        }
    }
    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);

    cin >> N;
    for (int i = 0; i < N; i++) {
        int x, y, p; cin >> x >> y >> p;
        cows[i] = { { x, y }, p };
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (dist(cows[i].first, cows[j].first) <= pow(cows[i].second, 2)) {
                adj_list[i].push_back(j);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < N; i++) {
        fill(visited, visited + N, false);
        ans = max(ans, dfs(i));
    }
    cout << ans << endl;
}