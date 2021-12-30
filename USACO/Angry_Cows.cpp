#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int N, K, ans;
set<int> haybales;

bool check(set<int> haybales, int r) {
    int count = 0;
    while (haybales.size() > 0) {
        int x = *haybales.begin();
        int max = x + 2 * r;
        auto cur = haybales.upper_bound(max);
        while (cur != haybales.begin()) {
            haybales.erase(prev(cur));
            cur = haybales.upper_bound(max);
        }
        count++;
    }
    return count <= K;
}

int firstTrue(int lo, int hi) {
	hi++;
	while (lo < hi) {
		int mid = lo + (hi - lo) / 2;
		if (check(haybales, mid)) {
			hi = mid;
		} else {
			lo = mid + 1;
		}
	}
	return lo;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);

    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        int pos; cin >> pos;
        haybales.insert(pos);
    }
    ans = firstTrue(0, *haybales.end());
    cout << ans << '\n';
}