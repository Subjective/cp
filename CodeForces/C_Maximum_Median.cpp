#include <bits/stdc++.h>

using namespace std;

int n, k, a[200000];

bool check(int x) {
    long long ops = 0;
    for (int i = (n - 1) / 2; i < n; i++) {
        ops += max(0, x - a[i]);
    }
    return ops <= k; 
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);

    int lo = 0, hi = 2e9;
    while (lo < hi) {
        int mid = lo + (hi - lo + 1) / 2;
        if (check(mid)) {
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }
    cout << lo << '\n';
}