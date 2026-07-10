#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, long long>>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    vector<long long> dist(n + 1, INF);
    vector<int> parent(n + 1, 0);

    dist[1] = 0;

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({0, 1});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u]) continue;

        if (u == n) break;

        for (auto [v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    if (dist[n] == INF) {
        cout << -1 << '\n';
    } else {
        vector<int> path;
        int cur = n;
        while (cur != 0) {
            path.push_back(cur);
            cur = parent[cur];
        }
        reverse(path.begin(), path.end());

        for (int i = 0; i < (int)path.size(); ++i) {
            cout << path[i] << (i == (int)path.size() - 1 ? '\n' : ' ');
        }
    }

    return 0;
}
