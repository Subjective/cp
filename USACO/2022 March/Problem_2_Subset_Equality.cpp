#include <bits/stdc++.h>

using namespace std;

string s, t, query;
int Q; 
int charsets[256];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  
  cin >> s >> t;

  for (char c = 'a'; c <= 'r'; c++) {
      auto s_it = s.begin(), t_it = t.begin();
      bool end = false, next = false;
      int runningSum[256] = {};
      charsets[(unsigned char)c] = (1 << 18) - 1;

      do {
          // continue until next matching character
          while (s_it != s.end() && *s_it != c) {
              runningSum[(unsigned char)*s_it]++;
              s_it++;
          }
          while (t_it != t.end() && *t_it != c) {
              runningSum[(unsigned char)*t_it]--;
              t_it++;
          }
          end = (s_it == s.end() && t_it == t.end());
          next = !end && (s_it == s.end() || t_it == t.end());

          if (!next) {
              s_it++;
              t_it++;

              int cur = 0;
              for (char x = 'a'; x <= 'r'; x++) {
                  if (runningSum[(unsigned char)x] == 0) {
                      cur = cur | (1 << (x - 'a'));
                  }
              }
              charsets[(unsigned char)c] &= cur;
          }
          else {
              charsets[(unsigned char)c] = 0;
          }
      } while (!end && !next);
  }

  cin >> Q;
  for (int i = 0; i < Q; i++) {
      cin >> query;
      int cur = (1 << 18) - 1;
      int queryset = 0;
      for (char c : query) {
          cur = cur & charsets[(unsigned char)c];
          queryset = queryset | (1 << (c - 'a'));
      }
      cur = cur & queryset;

      // check if query matches intersection
      if (cur == queryset) {
          cout << "Y";
      } else {
          cout << "N";
      }
  }
}