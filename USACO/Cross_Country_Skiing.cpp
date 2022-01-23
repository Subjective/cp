#include <bits/stdc++.h>

using namespace std;

const int mxN = 505;

int M, N, max_e = INT_MIN, min_e = INT_MAX;
int elevations[mxN][mxN];
vector<pair<int, int>> waypoints;
bool visited[mxN][mxN];

void floodfill(int r, int c, int prev_e, int d) {
    int cur_e = elevations[r][c];
    if (r < 1 || r > M || c < 1 || c > N || visited[r][c] || abs(cur_e - prev_e) > d) {
        return;
    }
    visited[r][c] = true;

    floodfill(r, c + 1, cur_e, d);
    floodfill(r, c - 1, cur_e, d);
    floodfill(r + 1, c, cur_e, d);
    floodfill(r - 1, c, cur_e, d);
}

bool check(int d) {
    fill(&visited[0][0], &visited[0][0] + sizeof(visited), false);
    int x = waypoints[0].first, y = waypoints[0].second;
    floodfill(x, y, elevations[x][y], d);
    for (auto coord : waypoints) {
        if (!visited[coord.first][coord.second]) {
            return false;
        }
    }
    return true;
}

int firstTrue(int lo, int hi) {
    hi++;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (check(mid)) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    return lo;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("ccski.in", "r", stdin);
    freopen("ccski.out", "w", stdout);

    cin >> M >> N;
    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
            int e; cin >> e;
            elevations[i][j] = e;
            max_e = max(max_e, e);
            min_e = min(min_e, e);
        }
    }
    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
            int x; cin >> x;
            if (x) {
                waypoints.push_back({ i , j });
            }
        }
    }
    cout << firstTrue(0, max_e - min_e) << '\n';
}
