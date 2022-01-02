#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> pre(n + 1, 0);
        string digits; cin >> digits;
        for (int i = 1; i <= n; i++) {
            pre[i] += pre[i - 1] + (digits[i - 1] - '0');
        }
        map<int, int> diffs;
        for (int i = 0; i <= n; i++) {
            diffs[pre[i] - i]++;
        }
        ll ans = 0;
        for (auto& diff : diffs) {
            int x = diff.second;
            ans += (ll) x * (x - 1) / 2;
        }
        cout << ans << '\n';
    }
}