#include <iostream>
#include <vector>
using namespace std;

const long long MOD = 1e9 + 7;

long long power(long long base, long long exp) {
    long long result = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % MOD;
        }
        base = (base * base) % MOD;
        exp /= 2;
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        sum = (sum + x % MOD + MOD) % MOD;
    }
    
    long long power_of_2 = power(2, n - 1);
    long long answer = (sum * power_of_2) % MOD;
    
    cout << answer << endl;
    
    return 0;
}