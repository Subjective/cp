#include <bits/stdc++.h>

using namespace std;

int n, sticks[200000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int length; cin >> length;
		sticks[i] = length;
	}
	sort(sticks, sticks + n);
	
	int x1 = sticks[n / 2], x2 = sticks[n / 2 + 1];
	long long t1 = 0, t2 = 0;
	for (int i = 0; i < n; i++) {
		t1 += abs(sticks[i] - x1);
		t2 += abs(sticks[i] - x2);
	}
	long long ans = min(t1, t2);
	cout << ans << '\n';
}
