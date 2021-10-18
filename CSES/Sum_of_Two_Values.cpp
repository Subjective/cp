#include <bits/stdc++.h>
using namespace std;

int n, x;
array<int, 2> a[200000];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        cin >> a[i][0];
        a[i][1] = i + 1;
    }
    sort(a, a + n);
    for (int left = 0, right = n - 1; left < right; ) {
        int sum = a[left][0] + a[right][0];
        if (sum == x) {
            cout << a[left][1] << " " << a[right][1] << '\n';
            exit(0);
        } else if (sum < x) {
            left++;
        } else {
            right--;
        }
    }
    cout << "IMPOSSIBLE" << '\n';
}