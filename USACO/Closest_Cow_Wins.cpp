#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int K, M, N;
    cin >> K >> M >> N;
    vector<pair<int, int>> patches(K + M);
    for (int i = 0; i < K; i++) {
        cin >> patches[i].first >> patches[i].second;
    }
    for (int i = K; i < K + M; i++) {
        cin >> patches[i].first;
        patches[i].second = -1;
    }
    sort(patches.begin(), patches.end());
    vector<ll> sums;
    int prev = -1;
    ll total_sum = 0;
    for (int i = 0; i < (int) patches.size(); i++) {
        if (patches[i].second == -1) {
            if (prev == -1) {
                sums.push_back(total_sum);
            } else {
                ll cur_sum = 0, best_sum = 0;
                for (int l = prev + 1, r = prev; l < i; l++) {
                    while (r + 1 < i && (patches[r + 1].first - patches[l].first) * 2 < patches[i].first - patches[prev].first) {
                        cur_sum += patches[++r].second;
                    }
                    best_sum = max(best_sum, cur_sum);
                    cur_sum -= patches[l].second;
                }
                sums.push_back(best_sum);
                sums.push_back(total_sum - best_sum);
            }
            prev = i;
            total_sum = 0;
        } else {
            total_sum += patches[i].second;
        }
    }
    sums.push_back(total_sum);
    sort(rbegin(sums), rend(sums));
    sums.resize(N);
    ll ans = 0;
    for (ll x : sums) {
        ans += x;
    }
    cout << ans << '\n';
}