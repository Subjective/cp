#include <bits/stdc++.h>
#include <locale>
using namespace std;

string s1, s2, q;
bool r[324];
int n;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> s1 >> s2 >> n;

    for (int i = 0; i < 17; i++) {
        for (int j = i + 1; j < 18; j++) {
            string t1 = "";
            string t2 = "";
            for (int k = 0; k < s1.length(); k++) {
                if (s1[k] == i + 'a' || s1[k] == j + 'a') {
                    t1 += s1[k];
                }
            }
            for (int k = 0; k < s2.length(); k++) {
                if (s2[k] == i + 'a' || s2[k] == j + 'a') {
                    t2 += s2[k];
                }
            }
            (t1 == t2) ? r[(18*i)+j] = true : r[(18*i)+j] = false;
        }
    }
    for (int i = 0; i < n; i++) {
        cin >> q;
        bool works = true;
        if (q.length() == 1) {
            int c1 = 0;
            int c2 = 0;
            for (int k = 0; k < s1.length(); k++) {
                if (s1[k] == q[0]) {
                    c1++;
                }
            }
            for (int k = 0; k < s2.length(); k++) {
                if (s2[k] == q[0]) {
                    c2++;
                }
            }
            if (c1 != c2) works = false;
        } else {
            for (int j = 0; j < q.length() - 1; j++) {
                for (int k = j + 1; k < q.length(); k++) {
                    if (!r[(18*(q[j]-'a'))+(q[k]-'a')]) {
                        works = false;
                        break;
                    }
                }
            }
        }

        (works) ? cout << "Y" : cout << "N";
    }
}