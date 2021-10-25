#include <bits/stdc++.h>

using namespace std;

int N;
pair<int, int> A[100000];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    freopen("sort.in", "r", stdin);
    freopen("sort.out", "w", stdout);

    cin >> N;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        A[i] = { num, i };
    }
    sort(A, A + N);
    
    int ans = - 1;
    for (int i = 0; i < N; i++) {
        ans = max(ans, A[i].second - i + 1);
    }
    cout << ans;
}