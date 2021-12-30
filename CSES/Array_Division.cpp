#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int n, k, A[200000];
ll sum, ans;

bool check(ll maxSum) {
    int count = 1;
    ll curSum = 0;
    for (int i = 0; i < n; i++) {
        if (A[i] > maxSum) return false;
        curSum += A[i];
        if (curSum > maxSum) {
            curSum = A[i];
            count++;
        }
    }
    return count <= k;
}

ll firstTrue(ll lo, ll hi) {
	hi++;
	while (lo < hi) {
		ll mid = lo + (hi - lo) / 2;
		if (check(mid)) {
			hi = mid;
		} else {
			lo = mid + 1;
		}
	}
	return lo;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        A[i] = a;
        sum += a;
    }
    ans = firstTrue(A[0], sum);
    cout << ans << '\n';
}