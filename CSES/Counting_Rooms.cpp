#include <bits/stdc++.h>

using namespace std;

const int mxN = 1000;

int n, m;
bool grid[mxN][mxN];
bool visited[mxN][mxN];

void floodfill(int r, int c) {
    if (r < 0 || r >= n || c < 0 || c >= m) return;
    if (!grid[r][c]) return;
    if (visited[r][c]) return;

    visited[r][c] = true;

    floodfill(r, c - 1);
    floodfill(r, c + 1);
    floodfill(r - 1, c);
    floodfill(r + 1, c);
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c; cin >> c;
            if (c == '.') grid[i][j] = true;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] && !visited[i][j]) {
                floodfill(i, j);
                ans++;
            }
        }
    }
    cout << ans << '\n';
}