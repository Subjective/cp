#include <bits/stdc++.h>

using namespace std;

int N, ans, pred[50000];
set<int> deck;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("highcard.in", "r", stdin);
    freopen("highcard.out", "w", stdout);

    cin >> N;
    for (int i = 1; i <= 2 * N; i++) {
        deck.insert(i);
    }
    for (int i = 0; i < N; i++) {
        int card; cin >> card;
        pred[i] = card;
        deck.erase(card);
    }
    for (int i = 0; i < N; i++) {
        auto higher_card = deck.upper_bound(pred[i]);
        if (higher_card != deck.end()) {
            deck.erase(*higher_card);
            ans++;
        } else {
            deck.erase(*deck.begin());
        }
    }
    cout << ans << '\n';
}
