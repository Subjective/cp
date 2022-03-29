#include <bits/stdc++.h>

using namespace std;

int N, ans;

void add_contribution_ss(vector<int>& h) { // sorted set
	vector<int> h_sorted(N + 1);
	for (int i = 0; i < N; ++i) h_sorted[h[i]] = i;
	set<int> present;
	for (int cur_h = N; cur_h; --cur_h) {
		auto it = present.insert(h_sorted[cur_h]).first;
		if (next(it) != end(present)) ans += *next(it)-*it+1;
	}
}

void add_contribution_ll(vector<int>& h) { // linked list
    vector<int> h_sorted(N + 1);
    for (int i = 0; i < N; i++) {
        h_sorted[h[i]] = i;
    }
    vector<int> pre(N), nex(N);
    for (int i = 0; i < N; i++) {
        pre[i] = i - 1;
        nex[i] = i + 1;
    }
    for (int cur_h = 1; cur_h <= N; cur_h++) {
        int pos = h_sorted[cur_h];
        int p = pre[pos], n = nex[pos];
        if (n != N) {
            ans += n - pos + 1;
            pre[n] = p;
        }
        if (p != -1) {
            nex[p] = n;
        }
    }
}

void add_contribution_stk(const vector<int> &h) { // stack
    stack<int> stk;
	for (int i = N-1; i >= 0; --i) {
		while (!stk.empty() && h[stk.top()] < h[i]) stk.pop();
		if (!stk.empty()) ans += stk.top() - i + 1;
		stk.push(i);
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    vector<int> h(N);
    for (int i = 0; i < N; i++) {
        cin >> h[i];
    }
    add_contribution_stk(h);
    reverse(h.begin(), h.end());
    add_contribution_stk(h);
    cout << ans << '\n';
}