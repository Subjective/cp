#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;
    vector<int> cows(N);
    for (int i = 0; i < N; i++) {
        cin >> cows[i];
    }
    long long ans = 0;
    for (int l = 0; l < N; l++) {
        int r = l;
        int start = cows[l];
        int prev_max = 0;
        while (r < N - 1) {
            r++;
            int cur = cows[r];
            if (cur > prev_max) {
                if (prev_max > start) {
                    break;
                }
                ans += r - l + 1;
                prev_max = cur;
            }
        }
    }
    cout << ans << '\n';
}