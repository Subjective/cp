#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int n;
ll x;
int a[200000];

int main(void) {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll sum = 0;
    int ans = 0;
    for (int left = 0, right = 0; right < n; right++) {
        sum += a[right];
        while (left < right && sum > x) {
            sum -= a[left++];
        }
        if (sum == x) ans++;
    }
    cout << ans << '\n';
}