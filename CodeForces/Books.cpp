#include <bits/stdc++.h>
using namespace std;

int n;
long long t;
int books[100000];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> t;
    for (int i = 0; i < n; i++) {
        cin >> books[i];
    }
    int ans = 0;
    int left = 0, right = 0, cur = 0;
    while (left < n && right < n) {
        while (right < n) {
            cur += books[right++];
            if (cur > t) {
                cur -= books[--right];
                break;
            }
        }
        ans = max(ans, right - left);
        cur -= books[left++];
    }
    cout << ans << '\n';
}