#include <bits/stdc++.h>

using namespace std;

int N, M;
pair<int, int> intervals[200000];
bool check(pair<int, int> p, int k) {
    return (k >= p.first && k <= p.second);
}

bool cmp(const pair<int, int>& x, pair<int, int>& y) {
    if (x.first == y.first) {
        return x.second < y.second;
    }
    return x.first < x.second;
}

int firstTrue(vector<pair<int, int>> vi, int lo, int hi, int k) {
	hi++;
	while (lo < hi) {
		int mid = lo + (hi - lo) / 2;
		if (check(vi[mid], k)) {
			hi = mid;
		} else {
			lo = mid + 1;
		}
	}
	return lo;
}

int lastTrue(vector<pair<int, int>> vi, int lo, int hi, int k) {
	lo--;
	while (lo < hi) {
		int mid = lo + (hi - lo + 1) / 2;
		if (check(vi[mid], k)) {
			lo = mid;
		} else {
			hi = mid - 1;
		}
	}
	return lo;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        intervals[i] = { a, b };
    }
    vector<pair<int, int>> ordered_pairs;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int a, b;
            a = intervals[i].first + intervals[j].first;
            b = intervals[i].second + intervals[j].second;
            ordered_pairs.push_back({ a, b });
        }
    }
    // for (pair<int, int> p : ordered_pairs) {
    //     cout << p.first << ' ' << p.second << '\n';
    // }
    sort(ordered_pairs.begin(), ordered_pairs.end(), cmp);
    for (int k = 0; k <= 2 * M; k++) {
        // cout << lastTrue(ordered_pairs, 0, N * N, k) << ' ' << firstTrue(ordered_pairs, 0, N * N - 1, k) << '\n';
        int ans = lastTrue(ordered_pairs, 0, N * N - 1, k) - firstTrue(ordered_pairs, 0, N * N - 1, k);
        cout << ans << '\n';
    }
}