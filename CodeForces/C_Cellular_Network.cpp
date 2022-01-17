#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(NULL)->sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector<int> cities(n);
    set<int> towers;
    for (int i = 0; i < n; i++) {
        cin >> cities[i];
    }
    for (int i = 0; i < m; i++) {
        int tower; cin >> tower;
        towers.insert(tower);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int dist = INT_MAX;
        auto closest = towers.lower_bound(cities[i]);
        if (closest != towers.end()) {
            dist = *closest - cities[i];
        }
        if (closest != towers.begin()) {
            closest--;
            dist = min(dist, cities[i] - *closest);
        }
        ans = max(ans, dist);
    }
    cout << ans << '\n';
}