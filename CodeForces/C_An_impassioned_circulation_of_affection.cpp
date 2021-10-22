#include <bits/stdc++.h>
using namespace std;

int n, q;
string garland;
int pre[26][1501];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> garland;

    garland = ' ' + garland;

    for (int i = 1; i <= n; i++) {
        int color = garland[i] - 'a';
        pre[color][i]++;
    }

    for (int i = 0; i < 26; i++) {
        for (int j = 1; j <= n; j++) {
            pre[i][j] += pre[i][j - 1];
        }
    }

    cin >> q;
    while (q--) {
        int m;
        char c;

        cin >> m >> c;
        int color_index = c - 'a';

        int l = 1, r = 1, koyomity = 1;
        while (r <= n) {
            int max_allowed = pre[color_index][r] - pre[color_index][l - 1] + m;
            if (max_allowed < r - l + 1) {
                l++;
            } else {
                koyomity = max(koyomity, r - l + 1);
                r++;
            }
        }
        cout << koyomity << '\n';
    }
}