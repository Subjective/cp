#include <bits/stdc++.h>

using namespace std;

const int mxN = 2e5 + 5;

string cow = "COW", s;
int Q, l, r;
int psums [mxN][3];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  
  cin >> s >> Q;
  for (int i = 1; i < (int) s.length() + 1; i++) {
    for (int j = 0; j < 3; j++) {
      psums[i][j] = psums[i - 1][j];
    }
    if (s[i - 1] == 'C') psums[i][0]++;
    if (s[i - 1] == 'O') psums[i][1]++;
    if (s[i - 1] == 'W') psums[i][2]++;
  }
  for (int i = 0; i < Q; i++) {
      cin >> l >> r;

      // initialize diffs 
      int diffs[3];
      for (int j = 0; j < 3; j++) {
        diffs[j] = psums[r][j] - psums[l - 1][j];
      }

      bool reduceable = false;
      if (diffs[0] % 2 == 1) {
        if (diffs[1] % 2 == 0 && diffs[2] % 2 == 0) {
          reduceable = true;
        }
      }
      else {
        if (diffs[1] % 2 == 1 && diffs[2] % 2 == 1) {
          reduceable = true;
        }
      }
      if (reduceable) {
        cout << "Y";
      } else {
        cout << "N";
      }
  }
}