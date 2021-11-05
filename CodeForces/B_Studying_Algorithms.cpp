#include <bits/stdc++.h>

using namespace std;

int n, x, a[100];

int main() {
    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    int ans = 0, cur = 0;
    // 3 3 4 4 7 8
    while (ans < n && cur + a[ans] <= x) {
        cur += a[ans];
        ans++;
    } 
    cout << ans << '\n';
}