#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, Omega;
    cin >> n >> Omega;

    vector<pair<ll, int>> holes(n);
    for (int i = 0; i < n; ++i) {
        cin >> holes[i].first;
        holes[i].second = i + 1;      // запоминаем исходный индекс дырки
    }

    sort(holes.begin(), holes.end()); // сортируем по массе по возрастанию

    ll current_mass = Omega;
    vector<int> order;

    for (int i = 0; i < n; ++i) {
        ll mass = holes[i].first;
        int idx = holes[i].second;

        if (mass < current_mass) {    // можно пройти дырку
            current_mass += mass;
            order.push_back(idx);
        } else {                      // застряли — ответа нет
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";
    for (int idx : order) {
        cout << idx << "\n";          // выводим порядок прохождения
    }

    return 0;
}