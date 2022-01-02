#include <bits/stdc++.h>

using namespace std;

int N, K, B, signals[100001], pre[100001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("maxcross.in", "r", stdin);
    freopen("maxcross.out", "w", stdout);

    cin >> N >> K >> B;
    while (B--) {
        int ID; cin >> ID;
        signals[ID]++;
    }
    for (int i = 1; i <= N; i++) {
        pre[i] = pre[i - 1] + signals[i];
    }
    int ans = INT_MAX;
    for (int i = 0; i <= N - K; i++) {
        ans = min(ans, pre[i + K] - pre[i]);
    }
    cout << ans << '\n';
}