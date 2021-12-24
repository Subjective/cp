#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int mxM = 5001;

int N, M;
ll a_freq[mxM], b_freq[mxM], a_sum_freq[2 * mxM], b_sum_freq[2 * mxM];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        ll a, b;
        cin >> a >> b;
        a_freq[a]++;
        b_freq[b]++;
    }

    for (int i = 0; i <= M; i++) {
        for (int j = 0; j <= M; j++) {
            a_sum_freq[i + j] += a_freq[i] * a_freq[j];
            b_sum_freq[i + j] += b_freq[i] * b_freq[j];
        }
    }

    ll sum = 0;
    for (int k = 0; k <= 2 * M; k++) {
        sum += a_sum_freq[k];
        cout << sum << '\n';
        sum -= b_sum_freq[k];
    }

}