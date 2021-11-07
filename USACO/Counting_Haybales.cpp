#include <bits/stdc++.h>

using namespace std;

int N, Q, haybales[100000];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> Q;
    for (int i = 0; i < N; i++) {
        cin >> haybales[i];
    }
    sort(haybales, haybales + N);
    for (int i = 0; i < Q; i++) {
        int A, B; cin >> A >> B;
        cout << upper_bound(haybales, haybales + N, B) - lower_bound(haybales, haybales + N, A) << '\n';
    }
}