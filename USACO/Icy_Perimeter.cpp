#include <bits/stdc++.h>

using namespace std;

const int mxN = 1005;

const int R_CHANGE[]{0, 1, 0, -1};
const int C_CHANGE[]{1, 0, -1, 0};

int N;
bool matrix[mxN][mxN];
bool visited[mxN][mxN];

int cur_area, cur_perimeter, max_area, perimeter;

void floodfill(int r, int c) {
    if (r < 0 || r > N + 1 || c < 0 || c > N + 1 || matrix[r][c] == false || visited[r][c]) {
        return;
    }
    visited[r][c] = true;
    cur_area++;
    for (int i = 0; i < 4; i++) {
        if (matrix[r + R_CHANGE[i]][c + C_CHANGE[i]] == false) {
            cur_perimeter++;
        }
    }
    
    for (int i = 0; i < 4; i++) {
        floodfill(r + R_CHANGE[i], c + C_CHANGE[i]);
    }

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("perimeter.in", "r", stdin);
    freopen("perimeter.out", "w", stdout);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            char x; cin >> x;
            x == '#' ? matrix[i][j] = true : matrix[i][j] = false;
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (!visited[i][j]) {
                floodfill(i, j);
            }
            if (max_area < cur_area) {
                max_area = cur_area;
                perimeter = cur_perimeter; 
            } else if (cur_area > 0 && max_area == cur_area) {
                perimeter = min(perimeter, cur_perimeter);
            }
            cur_area = 0, cur_perimeter = 0;
        }
    }
    cout << max_area << " " << perimeter << '\n';
}