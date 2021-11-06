#include <bits/stdc++.h>

using namespace std;

using ll = long long;

struct event {
    ll time;
    int id;
    bool enters;
};

bool cmp(const event& a, const event& b) { return a.time < b.time; }

int main() {
    cin.tie(0)->sync_with_stdio(0);

    freopen("lifeguards.in", "r", stdin);
    freopen("lifeguards.out", "w", stdout);

    int n;
    cin >> n;
    vector<event> events; 
    for (int i = 0; i < n; i++) {
        ll t1, t2; cin >> t1 >> t2;
        events.push_back(event { t1, i, true });
        events.push_back(event { t2, i, false });
    }
    sort(events.begin(), events.end(), cmp);

    vector<ll> aloneTime(n, 0);
    set<int> activeCows;

    ll total = 0, prev = 0;
    for (auto e : events) {
        ll cur = e.time;
        if (activeCows.size() > 0) {
            total += cur - prev;
        }
        if (activeCows.size() == 1) {
            aloneTime[*activeCows.begin()] += cur - prev;
        }
        if (e.enters) {
            activeCows.insert(e.id);
        } else {
            activeCows.erase(e.id);
        }
        prev = cur;
    }

    ll minAloneTime = LLONG_MAX;
    for (int i = 0; i < n; i++) {
        minAloneTime = min(minAloneTime, aloneTime[i]);
    }
    cout << total - minAloneTime << '\n';
}