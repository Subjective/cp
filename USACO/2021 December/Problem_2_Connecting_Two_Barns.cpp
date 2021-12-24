#include <bits/stdc++.h>

using namespace std;

const int mxN = 10e5 + 5;
int N, M, T;
vector<int> adj_list[mxN];
bool vis[mxN];
set<int> reps[mxN];

void dfs(int u, int comp) {
    reps[comp].insert(u);
    vis[u] = true; 
    for (int v : adj_list[u]) {
        if (!vis[v]) {
            dfs(v, comp);
        }
    }
}

int count_components() {
    int count = 0;
    for (int i = 1; i <= N; i++) {
        if (!vis[i]) {
            count++;
            dfs(i, count);
        }
    }
    return count;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> T;
    while (T--) {
        fill(adj_list, adj_list + mxN, vector<int>{});
        fill(vis, vis + mxN, false);
        fill(reps, reps + mxN, set<int>{});
        cin >> N >> M;
        for (int i = 0; i < M; i++) {
            int a, b; cin >> a >> b;
            adj_list[a].push_back(b);
            adj_list[b].push_back(a);
        }
        int count = count_components();
        int rep1 = 0, repn = 0;
        for (int i = 1; i <= count; i++) {
            if (reps[i].count(1) > 0) {
                rep1 = i;
            }
            if (reps[i].count(N) > 0) {
                repn = i;
            }
        }

        int minRepn = *(reps[repn].begin());
        int maxRep1 = *(reps[rep1].rbegin());
        if (minRepn == maxRep1) {
            cout << 0;
            return 0;
        }
        int min1 = (minRepn - maxRep1) * (minRepn - maxRep1);
        set<int> s;
        for (int i = 1; i <= count; i++) {
            if (i != rep1 && i != repn) {
                for (int node : reps[i]) {
                    s.insert(node);
                }
            }
        }
        int mid1 = *(s.lower_bound((minRepn + maxRep1) / 2));
        int mid2 = *((s.lower_bound((minRepn + maxRep1) / 2))++);
        int min2 = min((mid1 - maxRep1) * (mid1 - maxRep1) + (minRepn - mid1) * (minRepn - mid2), (mid2 - maxRep1) * (mid2 - maxRep1) + (minRepn - mid2) * (minRepn - mid2));
        cout << min(min1, min2) << '\n';

    }
}