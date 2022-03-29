#include <bits/stdc++.h>

using namespace std;

const int mxN = 1e5 + 5;

string s, t, query;
int Q;
int s_count[256][mxN];
int t_count[256][mxN];
int charsets[256];

int main() {
    cin >> s >> t;
    int s_length = s.length(); int t_length = t.length();
    // populate freq table for s
    for (auto s_it = s.begin(); s_it < s.end(); s_it++) {
        s_count[(unsigned char)*s_it][s_it - s.begin() + 1]++;
    }
    for (char c = 'a'; c <= 'r'; c++) {
        for (int i = 1; i <= s_length; i++) {
            s_count[(unsigned char)c][i] += s_count[(unsigned char)c][i - 1];
        }
    }
    // populate freq table for t
    for (auto t_it = t.begin(); t_it < t.end(); t_it++) {
        t_count[(unsigned char)*t_it][t_it - t.begin() + 1]++;
    }
    for (char c = 'a'; c <= 'r'; c++) {
        for (int i = 1; i <= t_length; i++) {
            t_count[(unsigned char)c][i] += t_count[(unsigned char)c][i - 1];
        }
    }


    for (char c = 'a'; c <= 'r'; c++) {
        auto s_it = s.begin(), t_it = t.begin();
        bool end = false, next = false;
        charsets[(unsigned char)c] = (1 << 18) - 1;
        do {
            while (s_it != s.end() && s[(unsigned char)*s_it] != c) s_it++;
            while (t_it != t.end() && t[(unsigned char)*t_it] != c) t_it++;
            end = (s_it == s.end() && t_it == t.end());
            next = !end && (s_it == s.end() || t_it == t.end());

            if (!next) {
                s_it++;
                t_it++;

                int valid = 0;
                for (char x = 'a'; x <= 'r'; x++) {
                    if (s_count[(unsigned char)x][s_it - s.begin() + 1] == t_count[(unsigned char)x][t_it - t.begin() + 1]) {
                        valid |= (1 << (x - 'a'));
                    }
                }
                charsets[(unsigned char)c] &= valid;
            }            
            else {
                charsets[(unsigned char)c] = 0;
            }
        } while (!end && !next);
    }

    for (int i = 0; i < Q; i++) {
        cin >> query;
        int cur = (1 << 18) - 1;
        int queryset = 0;
        for (char c : query) {
            cur &= charsets[(unsigned char)c];
            queryset |= (1 << (c - 'a'));
        }
        cur &= queryset;
        if (cur == queryset) {
          cout << "Y";
        } else {
          cout << "N";
        }
    }
}