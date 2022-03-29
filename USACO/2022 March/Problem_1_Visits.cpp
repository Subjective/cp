#include <bits/stdc++.h>

using namespace std;

const int mxN = 1e5 + 5;

int N, rep[mxN][3], edgeTo[mxN];
long long ans, mins;
pair<int, int> visits[mxN];
bool marked[mxN], onStack[mxN];
vector<int> cycle;

void dfs(int v) {
    onStack[v] = true;
    marked[v] = true;
    int u = visits[v].first;
    if (!marked[u]) {
        edgeTo[u] = v;
        dfs(u);
    } else if (onStack[u]) {
        for (int x = v; x != u; x = edgeTo[x]) {
            cycle.push_back(x);
        }
        cycle.push_back(u);
        // cycle.push_back(v);
    }
    onStack[v] = false;
}

void calculate_mins() {
    int count = 0;
    for (int i = 1; i <= N; i++) {
        if (!marked[i]) {
            rep[count][0] = i;
            dfs(i);
            if (cycle.size() > 0) {
                int minimum = INT_MAX;
                int sum = 0;
                for (auto x : cycle) {
                    sum += visits[x].second;
                    minimum = min(minimum, visits[x].second);
                }
                rep[count][1] = minimum;
                cycle.clear();
            }
            count++;
        }
    }
    for (int i = 0; i < count; i++) {
        mins += rep[i][1];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        int a, v; cin >> a >> v;
        visits[i] = { a, v };
    }
    calculate_mins();
    for (int i = 1; i <= N; i++) {
        ans += visits[i].second;
    }
    cout << ans - mins;
}