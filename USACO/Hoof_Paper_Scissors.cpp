#include <bits/stdc++.h>

using namespace std;

const int mxN = 1e5;

int N, ans, hoof[mxN], paper[mxN], scissors[mxN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        char pred; cin >> pred;

        paper[i] += paper[i - 1];
        scissors[i] += scissors[i - 1];
        hoof[i] += hoof[i - 1];

        if (pred == 'H') {
            paper[i]++;
        } else if (pred == 'P') {
            scissors[i]++;
        } else {
            hoof[i]++;
        }
    }

    for (int i = 1; i <= N; i++) {
        int maxStart = max(max(hoof[i], paper[i]), scissors[i]);
        int maxEnd = max(max(hoof[N] - hoof[i], paper[N] - paper[i]), scissors[N] - scissors[i]);
        ans = max(ans, maxStart + maxEnd);
    }
    cout << ans << '\n';
}