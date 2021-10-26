#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

int n, x;
pii A[5000];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        int a; cin >> a; 
        A[i] = { a, i + 1 };
    }
    sort(A, A + n);
    for (int middle = 0; middle < n; middle++) {
        int target = x - A[middle].first;
        for (int left = 0, right = n - 1; left < right; ) {
            if (left != middle && right != middle && A[left].first + A[right].first == target) {
                cout << A[left].second << ' ' << A[right].second << ' ' << A[middle].second << '\n';
                return 0;
            }
            if (A[left].first + A[right].first > target) {
                right--;
            } else {
                left++;
            }
        }
    }
    cout << "IMPOSSIBLE" << '\n';
}