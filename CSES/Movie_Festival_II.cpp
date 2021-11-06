#include <bits/stdc++.h>

using namespace std;

int n, k;
pair<int, int> movies[200000];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> movies[i].second >> movies[i].first;
    }
    sort(movies, movies + n); 
    
    int ans = 0;
    multiset<int> end_times;
    for (int i = 0; i < k; i++) {
        end_times.insert(0);
    }

    for (int i = 0; i < n; i++) {
        auto it = end_times.upper_bound(movies[i].second);
        if (it == begin(end_times)) continue;
        end_times.erase(--it);

        end_times.insert(movies[i].first);
        ans++;
    }

    cout << ans;
}