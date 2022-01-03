#include <bits/stdc++.h>

using namespace std;

const int MAX = 799;

int N, K, field[MAX][MAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("lazy.in", "r", stdin);
    freopen("lazy.out", "w", stdout);

    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> field[i + j][N - 1 - i + j];
        }
    }
    
    int parity = (N + 1) % 2;
    N = 2 * N - 1;

    int best = 0;
    for (int i = 0; i < N; i++, parity = 1 - parity) {
        int cur = 0;
        for (int a = max(i - K, 0); a < N && a <= i + K; a++) {
            for (int b = 0; b < N && b <= parity + K; b++) {
                cur += field[a][b];
            }
        }
        best = max(best, cur);
        for (int j = parity + 1; j + K < N; j++) {
            for (int a = max(i - K, 0); a < N && a <= i + K; a++) {
                if (j - K - 1 >= 0) {
                    cur -= field[a][j - K - 1];
                }
                cur += field[a][j + K];
            }
            if (j % 2 == parity) {
                best = max(best, cur);
            }
        }
    }
    cout << best << '\n';
}