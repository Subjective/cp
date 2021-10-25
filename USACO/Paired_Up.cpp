#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("pairup.in", "r", stdin);
    freopen("pairup.out", "w", stdout);

    int N; cin >> N;
    vector<pair<int, int>> A(N);
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        A[i] = { y, x };
    }
    sort(A.begin(), A.end());

    int ans = 0, left = 0, right = N - 1;
    while (left <= right) {
        int sub = min(A[left].second, A[right].second);
        if (left == right) sub /= 2;
        ans = max(ans, A[left].first + A[right].first);
        A[left].second -= sub;
        A[right].second -= sub;
        if (A[left].second == 0) left++;
        if (A[right].second == 0) right--;
    }
    cout << ans << '\n';
}