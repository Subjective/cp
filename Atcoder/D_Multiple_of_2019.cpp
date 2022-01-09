#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(NULL)->sync_with_stdio(false);
    
    string s; cin >> s;
    int n = s.size(), num = 0, pow = 1;
    int count[2019]{ 1 };
    for (int i = n - 1; i >= 0; i--) {
        num = (num + pow * (s[i] - '0')) % 2019;
        count[num]++;
        pow = pow * 10 % 2019;
    }
    long long ans = 0;
    for (int i = 0; i < 2019; i++) {
        ans += (long long) count[i] * (count[i] - 1) / 2;
    }
    cout << ans << '\n';
}