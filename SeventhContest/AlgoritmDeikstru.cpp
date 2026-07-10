#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m, s;
    cin >> n >> m >> s;
    
    vector<vector<pair<int, int>>> graph(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});  // граф неориентированный
    }
    
    vector<int> width(n + 1, -1);
    width[s] = 1e9 + 1;  // стартовая вершина имеет "бесконечную" ширину
    
    priority_queue<pair<int, int>> pq;  // max-heap по ширине
    pq.push({width[s], s});
    
    while (!pq.empty()) {
        auto [w, u] = pq.top();
        pq.pop();
        
        if (w != width[u]) continue;  // устаревшая запись — пропускаем
        
        for (auto [v, edge_w] : graph[u]) {
            int new_width = min(width[u], edge_w);  // ширина пути = минимум на ребре
            if (new_width > width[v]) {  // нашли более широкий путь
                width[v] = new_width;
                pq.push({width[v], v});
            }
        }
    }
    
    for (int i = 1; i <= n; i++) {
        if (i == s) {
            cout << -1 << " ";  // для стартовой вершины выводим -1
        } else {
            cout << width[i] << " ";
        }
    }
    cout << endl;
    
    return 0;
}