#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while (t--) {
        long long n;
        cin >> n;
        
        // Особый случай: произведение цифр = 0 возможно только для числа 10
        if (n == 0) {
            cout << "10\n";
            continue;
        }
        
        // Особый случай: произведение цифр = 1 — это число 1
        if (n == 1) {
            cout << "1\n";
            continue;
        }
        
        vector<int> digits;
        
        // Жадно делим на самые большие цифры (9..2), чтобы цифр было меньше
        for (int d = 9; d >= 2; d--) {
            while (n % d == 0) {
                digits.push_back(d);
                n /= d;
            }
        }
        
        // Если после деления n != 1, значит есть простой множитель > 9 — разложить нельзя
        if (n != 1) {
            cout << "-1\n";
            continue;
        }
        
        // Сортируем по возрастанию, чтобы получить минимальное число
        sort(digits.begin(), digits.end());
        
        for (int d : digits) {
            cout << d;
        }
        cout << "\n";
    }
    
    return 0;
}