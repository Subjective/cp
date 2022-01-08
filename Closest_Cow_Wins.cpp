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
    
    for (int i = 0; i < M; i++) {
        cin >> patches[i].first;
        patches[i].second = -1;
    }
    sort(patches.begin(), patches.end());
    vector<ll> sums;
    int prev_i = -1;
    ll total_sum = 0;
    for (int i = 0; i < patches.size(); i++) {
        if (patches[i].second == -1) {
            if (prev_i == -1) {
                sums.push_back(total_sum);
            } else {
                ll cur_sum = 0, best_sum = 0;
            }
        }
    }
}