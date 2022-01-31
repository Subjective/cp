#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b, c;
    cin >> a >> b >> c;
    int m; cin >> m;

    priority_queue<int, vector<int>, greater<int>> usb, ps2;

    for (int i = 0; i < m; i++) {
        int cost;
        string type;
        cin >> cost >> type;
        if (type == "USB") {
            usb.push(cost);
        } else {
            ps2.push(cost);
        }
    }
    int count = 0;
    long long total_cost = 0;
    while (!usb.empty() && a--) {
        total_cost += usb.top();
        usb.pop();
        count++;
    }
    while (!ps2.empty() && b--) {
        total_cost += ps2.top();
        ps2.pop();
        count++;
    }
    while ((!usb.empty() || !ps2.empty()) && c--) {
        int usb_cost = INT_MAX, ps2_cost = INT_MAX;
        if (!usb.empty()) {
            usb_cost = usb.top();
        }
        if (!ps2.empty()) {
            ps2_cost = ps2.top();
        }
        if (usb_cost < ps2_cost) {
            total_cost += usb_cost;
            usb.pop();
        } else {
            total_cost += ps2_cost;
            ps2.pop();
        }
        count++;
    }
    cout << count << ' ' << total_cost << '\n';
}