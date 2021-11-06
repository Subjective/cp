#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
pair<int, int> tasks[200000];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        tasks[i] = { a, b };
    }
    sort(tasks, tasks + n);
    ll time = 0, ans = 0;
    for (int i = 0; i < n;i ++) {
        time += tasks[i].first;
        ans += tasks[i].second - time;
    }
    cout << ans << '\n';
}