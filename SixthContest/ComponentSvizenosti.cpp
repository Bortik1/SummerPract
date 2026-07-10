#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> graph;
vector<bool> visited;

void dfs(int v) {
    visited[v] = true;  // помечаем вершину как посещённую
    for (int u : graph[v]) {
        if (!visited[u]) {
            dfs(u);  // рекурсивно обходим всех непосещённых соседей
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;  // n вершин, m рёбер
    
    graph.resize(n + 1);
    visited.resize(n + 1, false);
    
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);  // добавляем ребро в обе стороны
        if (u != v) {
            graph[v].push_back(u);
        }
    }
    
    int components = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {  // нашли новую компоненту связности
            components++;
            dfs(i);  // обходим всю компоненту
        }
    }
    
    cout << components << endl;
    
    return 0;
}