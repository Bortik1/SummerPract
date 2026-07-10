#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }

    // dp[i][j] = максимальное золото при достижении клетки (i, j)
    vector<vector<int>> dp(n, vector<int>(m, 0));
    dp[0][0] = a[0][0];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i == 0 && j == 0) continue;

            int best = -1;  // -1 означает "недостижимо"

            if (i > 0 && dp[i-1][j] >= 0)
                best = max(best, dp[i-1][j]);      // пришли сверху
            if (j > 0 && dp[i][j-1] >= 0)
                best = max(best, dp[i][j-1]);      // пришли слева
            if (i > 0 && j > 0 && dp[i-1][j-1] >= 0)
                best = max(best, dp[i-1][j-1]);    // пришли по диагонали

            if (best >= 0) {
                dp[i][j] = best + a[i][j];
            } else {
                dp[i][j] = -1;  // недостижимо
            }
        }
    }

    cout << dp[n-1][m-1] << "\n";

    return 0;
}