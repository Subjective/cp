#include <bits/stdc++.h>

using namespace std;

int n, loc[60000], speed[60000];

bool check(long double time) {
    long double max_left = 0, min_right = 2e9;     
    for (int i = 0; i < n; i++) {
        long double cur_left, cur_right, cur_loc = loc[i], cur_speed = speed[i]; 
        cur_left = cur_loc - cur_speed * time;
        cur_right = cur_loc + cur_speed * time;
        max_left = max(max_left, cur_left);
        min_right = min(min_right, cur_right);
    }
    if (max_left > min_right) return false;
    return true;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> loc[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> speed[i];
    }

    long double l = 0, r = 1e9;
    const long double eps = 1e-9;
    while (l + eps < r) {
        long double mid = (l + r) / 2; 
        if (check(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    cout << setprecision(18) << l << '\n';
}