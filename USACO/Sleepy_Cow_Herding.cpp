#include <bits/stdc++.h>

using namespace std;

int N, cows[100000];

int solve_min() {
    int max_cows = 0;
    if (cows[N - 2] - cows[0] + 1 == N - 1 && cows[N - 1] - cows[N - 2] > 2) return 2;
    if (cows[N - 1] - cows[1] + 1 == N - 1 && cows[1] - cows[0] > 2) return 2;
    for (int i = 0, j = 0; i < N; i++) {
        while (j < N - 1 && cows[j + 1] - cows[i] + 1 <= N) j++;
        max_cows = max(max_cows, j - i + 1);
    }
    return N - max_cows;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("herding.in", "r", stdin);
    freopen("herding.out", "w", stdout);

    cin >> N;
    for (int i; i < N; i++) {
        cin >> cows[i];
    }
    sort(cows, cows + N);

    int min_ans = solve_min();
    int max_ans = max(cows[N - 2] - cows[0], cows[N - 1] - cows[1]) - N + 2;

    cout << min_ans << '\n' << max_ans << '\n';
}