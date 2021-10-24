#include <bits/stdc++.h>

using namespace std;

int n, m, h, t; 
multiset<int> tickets;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    while (n--) {
        cin >> h;
        tickets.insert(h);
    }
    for (int i = 0; i < m; i++) {
        cin >> t;
        auto it = tickets.upper_bound(t);
        if (it == tickets.begin()) {
            cout << -1 << '\n';
        } else {
            cout << *(--it) << '\n';
            tickets.erase(it);
        }
    }
}