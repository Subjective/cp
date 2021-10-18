#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define X first
#define Y second

int N;
pair<ll, ll> cows[50000];
pair<ll, ll> m = { INT_MAX, INT_MAX }, M = { 0, 0 };

bool compx(pair<ll, ll> a, pair<ll, ll> b) { return a.X < b.X; }
bool compy(pair<ll, ll> a, pair<ll, ll> b) { return a.Y < b.Y; }

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	freopen("split.in", "r", stdin);
	freopen("split.out", "w", stdout);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> cows[i].X >> cows[i].Y;
	}

	for (int i = 0; i < N; i++) {
		m.X = min(m.X, cows[i].X);
		m.Y = min(m.Y, cows[i].Y);
		M.X = max(M.X, cows[i].X);
		M.Y = max(M.Y, cows[i].Y);
	}

	ll ans = LLONG_MAX;

	for (int t = 0; t < 2; t++) {
		sort(cows, cows + N, compx);
		multiset<int> L, R;
	
		for (int i = 0; i < N; i++) {
			R.insert(cows[i].Y);
		}
		for (int i = 0; i < N - 1; i++) {
			L.insert(cows[i].Y);
			R.erase(R.find(cows[i].Y));

			if (cows[i].X == cows[i + 1].X) 
				continue;

			ll left_area = (cows[i].X - cows[0].X) * (*L.rbegin() - *L.begin());
			ll right_area = (cows[N - 1].X - cows[i + 1].X) * (*R.rbegin() - *R.begin());

			ans = min(ans, left_area + right_area);
		}
		for (int i = 0; i < N; i++) {
			swap(cows[i].X, cows[i].Y);
		}
	}

	cout << (M.X - m.X) * (M.Y - m.Y) - ans << '\n';
}