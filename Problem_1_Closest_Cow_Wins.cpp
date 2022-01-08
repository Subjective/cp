#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int K, M, N;
map<int, int> patches;
vector<int> nhoj_cows;
vector<ll> sums;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> K >> M >> N;
    for (int i = 0; i < K; i++) {
        int p, t; cin >> p >> t;
        patches.insert({ p, t });
    }
    for (int i = 0; i < M; i++) {
        int f; cin >> f;
        nhoj_cows.push_back(f);
    }
    sort(nhoj_cows.begin(), nhoj_cows.end());
    ll left_sum = 0;
    int left_cow = nhoj_cows[0]; 
    auto upper = patches.upper_bound(left_cow);
    for (auto it = patches.begin(); it != upper; it++) {
        left_sum += it->second;
    }
    sums.push_back(left_sum);
    int prev = left_cow, cur;
    for (int i = 1; i < M; i++) {
        cur = nhoj_cows[i];
        // max tastiness in interval with one cow
        ll one_sum = 0;
        for (int i = prev; i <= cur; i++) {
            ll sum = 0;
            int l = (prev + i) / 2, r = (cur + i) / 2;
            auto lo = patches.upper_bound(l), hi = patches.upper_bound(r);
            while (lo != hi) {
                sum += lo->second;
                lo++;
            } 
            one_sum = max(one_sum, sum);
        }
        sums.push_back(one_sum);
        // tastiness in interval with two cows
        auto lo = patches.upper_bound(prev), hi = patches.upper_bound(cur);
        ll two_sum = 0;
        while (lo != hi) {
            two_sum += lo->second;
            lo++;
        }
        sums.push_back(two_sum - one_sum);
        
        prev = cur;
    }
    ll right_sum = 0;
    for (auto it = patches.upper_bound(cur); it != patches.end(); it++) {
        right_sum += it->second;
    }
    sums.push_back(right_sum);

    sort(sums.rbegin(), sums.rend());
    sums.resize(N);
    int ans = 0;
    for (int x : sums) {
        ans += x;
    }
    cout << ans << '\n';
}