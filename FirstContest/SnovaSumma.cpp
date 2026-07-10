#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    __int128 sum = 0;                          // аккумулятор точной суммы (128 бит)
    const ll SCALE = 1000000000000000LL;       // 10^15: масштаб для 15 знаков после точки

    while (cin >> s) {
        size_t dot_pos = s.find('.');
        string int_part = s.substr(0, dot_pos);
        string frac_part = s.substr(dot_pos + 1);

        ll int_val = stoll(int_part);
        ll frac_val = stoll(frac_part);

        sum += (__int128)int_val * SCALE + frac_val;  // переводим в fixed-point и накапливаем
    }

    ll res_int = sum / SCALE;                         // целая часть результата
    ll res_frac = sum % SCALE;                        // дробная часть результата

    cout << res_int << ".";
    cout << setw(15) << setfill('0') << res_frac << '\n';  // выводим дробь с ведущими нулями

    return 0;
}