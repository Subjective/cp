#include <bits/stdc++.h>

using namespace std;

int n, x;
long long A[200000];
map<long long, int> sums;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    long long prefix_sum = 0;
    long long ans = 0;
    sums[0] = 1;
    for (int i = 0; i < n; i++) {
        prefix_sum += A[i];
        ans += sums[prefix_sum - x];
        sums[prefix_sum]++;
    }
    cout << ans << '\n';
}