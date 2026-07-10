#include <iostream>
using namespace std;

const long long MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    // Вычисляем (n-1)!
    long long fact = 1;
    for (int i = 2; i <= n - 1; i++) {
        fact = (fact * i) % MOD;
    }
    
    // Делим на 2 (умножаем на обратный элемент по модулю)
    // Обратный элемент к 2 по модулю 10^9 + 7 равен 500000004
    long long inv2 = 500000004;
    long long ans = (fact * inv2) % MOD;
    
    cout << ans << endl;
    
    return 0;
}