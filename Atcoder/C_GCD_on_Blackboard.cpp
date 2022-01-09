#include <bits/stdc++.h>

using namespace std;

const int mxN = 1e5 + 2;

int N, A[mxN], prefix[mxN], suffix[mxN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    for (int i = 1; i <= N; i++) {
        prefix[i] = gcd(prefix[i - 1], A[i]);
    }
    for (int i = N; i >= 1; i--) {
        suffix[i] = gcd(suffix[i + 1], A[i]);
    }
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        ans = max(ans, gcd(prefix[i - 1], suffix[i + 1]));
    }
    cout << ans << '\n';
}