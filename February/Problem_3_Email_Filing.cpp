#include <bits/stdc++.h>

using namespace std;

void solve() {
    int M, N, K;
    cin >> M >> N >> K;

    vector<deque<int>> A(M);
    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        x--;
        A[x].push_front(i);
    }

    int max_val = INT_MIN;
    for (int i = 0; i < K; i++) {
        max_val = max(max_val, A[i].front());
    }
    for (int i = K; i <= M - 2 * K; i += K) {
        int cur_max = INT_MIN;
        for (int j = 0; j < K; j++) {
            if (A[i + j].back() < max_val) {
                cout << "NO" << '\n';
                return;
            }
            cur_max = max(cur_max, A[i + j].front());
        }
        max_val = max(max_val, cur_max);
    }
    cout << "YES" << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        solve();
    }

}