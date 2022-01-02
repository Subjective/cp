#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int n, A[200000], sums[200000];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    ll prefix_sum = 0;
    ll ans = 0;

    sums[0] = 1;
    for (int i = 0; i < n; i++) {
        prefix_sum = ((prefix_sum + A[i]) % n + n) % n;
        ans += sums[prefix_sum];
        sums[prefix_sum]++;
    }
    cout << ans << '\n';
}