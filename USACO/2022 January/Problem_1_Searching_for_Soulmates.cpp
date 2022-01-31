#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int solve() {
    ll a, b; cin >> a >> b;
    int count = 0;
    unordered_map<ll, int> path;

    path[a] = 1;
    while (a != 1) {
        if (a % 2 == 1) {
            a++;
        } else {
            a /= 2;
        }
        count++;
        path[a] = count;
    }
    count = 0;
    while (path.find(b) == path.end()) {
        if (b % 2 == 1) {
            b--;
        } else {
            b /= 2;
        }
        count++;
    }
    int total_count = count + path[b];
    return --total_count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;
    while (N--) {
        cout << solve() << '\n';
    }
}