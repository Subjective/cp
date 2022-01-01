#include <bits/stdc++.h>

using namespace std;

int n, x;
long long pre[200001];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        cin >> pre[i];
        pre[i] += pre[i - 1];
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <=n; j++) {
            if (pre[j] - pre[i - 1] == x) {
                ans++;
            }
        }
    }
    cout << ans << '\n';
}