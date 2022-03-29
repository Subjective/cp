#include<bits/stdc++.h>

using namespace std;

string s, t;
int s_length, t_length;
int Q;
unordered_set<char> query_set;

bool query(string q) {
    query_set.clear();
    for (auto &ch : q) {
        query_set.insert(ch);
    }
    int i = 0; int j = 0;
    bool found_s = false;
    bool found_t = false;
    while (true) {
        if (i == s_length && j == t_length) {
            return true;
        }
        while (i < s_length) {
            if (query_set.count(s[i]) == 0) {
                i++;
            } else {
                found_s = true;
            }
            
        }
        while (j < t_length) {
            if (query_set.count(t[j]) == 0) {
                j++;
            } else {
                found_t = true;
            }
        }
        if (found_s && found_t && s[i] != t[j]) {
            return false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s >> t >> Q;
    s_length = (int) s.length();
    t_length = (int) t.length();

    for (int i = 0; i < Q; i++) {
        string q; cin >> q;
        if (query(q) == true) cout << 'Y';
        else cout << 'N';
    }
        
}