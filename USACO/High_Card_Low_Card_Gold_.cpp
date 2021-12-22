#include <bits/stdc++.h>

using namespace std;

int N, ans, elsie_cards[50000];
set<int> bessie_cards, lower_half, upper_half;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("cardgame.in", "r", stdin);
    freopen("cardgame.out", "w", stdout);

    cin >> N;
    for (int i = 1; i <= 2 * N; i++) {
        bessie_cards.insert(i);
    }
    for (int i = 0; i < N; i++) {
        int card; cin >> card;
        elsie_cards[i] = card;
        bessie_cards.erase(card);
    }
    for (int i = 0; i < N / 2; i++) {
        lower_half.insert(*bessie_cards.begin());
        bessie_cards.erase(*bessie_cards.begin());
    }
    for (int i = 0; i < N / 2; i++) {
        upper_half.insert(*bessie_cards.begin());
        bessie_cards.erase(*bessie_cards.begin());
    }

    for (int i = 0; i < N / 2; i++) {
        auto higher_card = upper_half.upper_bound(elsie_cards[i]);
        if (higher_card != upper_half.end()) {
            upper_half.erase(higher_card);
            ans++;
        } else {
            upper_half.erase(upper_half.begin());
        }
    }
    for (int i = N / 2; i < N; i++) {
        auto lower_card = lower_half.upper_bound(elsie_cards[i]);
        if (lower_card != lower_half.begin()) {
            lower_card--;
            lower_half.erase(lower_card);
            ans++;
        } else {
            lower_half.erase(prev(lower_half.end()));
        }
    }
    cout << ans << '\n';
}