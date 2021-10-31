#include <bits/stdc++.h>

using namespace std;

int n;
pair<int, int> movies[200000];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        movies[i] = { b, a };
    }
    sort(movies, movies + n);
    int currEndTime = INT_MIN;
    int ans = 0;
    for (int i = 0; i < n; i++) {
       if (movies[i].second >= currEndTime) {
           currEndTime = movies[i].first;
           ans++;
       } 
    }
    cout << ans << '\n';
}