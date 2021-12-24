#include <bits/stdc++.h>

using namespace std;

const int mxN = 50005;

int N, K, ans, diamonds[mxN], maxLengthAtI[mxN], maxLengthAfterI[mxN];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);

    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> diamonds[i];
    }
    sort(diamonds, diamonds + N);

    int l = 0, r = 0;
    while (l < N) {
        if (diamonds[r] - diamonds[l] <= K && r < N) {
            r++;
        } else {
            maxLengthAtI[l] = r - l;
            l++;
        }
    }

    maxLengthAfterI[N] = 0;
    for (int i = N - 1; i >= 0; i--) {
        maxLengthAfterI[i] = max(maxLengthAfterI[i + 1], maxLengthAtI[i]);
    }

    for (int i = 0; i < N; i++) {
        ans = max(ans, maxLengthAtI[i] + maxLengthAfterI[i + maxLengthAtI[i]]);
    } 
    cout << ans << '\n';
}