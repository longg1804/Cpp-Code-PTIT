#include <bits/stdc++.h>
using namespace std;

void bfs(int start, int target, vector<vector<int>>& graph, vector<int>& parent, int n) {
    vector<bool> visited(n + 1, false);
    queue<int> q;
    q.push(start);
    visited[start] = true;
    parent[start] = -1;
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        if (current == target) return;
        for (int neighbor : graph[current])
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                parent[neighbor] = current;
                q.push(neighbor);
            }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E, u, v;
        cin >> V >> E >> u >> v;
        vector<vector<int>> graph(V + 1);
        for (int i = 0; i < E; i++) {
            int x, y;
            cin >> x >> y;
            graph[x].push_back(y);
        }
        vector<int> parent(V + 1, -1);
        bfs(u, v, graph, parent, V);
        if (parent[v] == -1) {
            if (u == v) 
                cout << u << endl;
            else cout << -1 << endl;
        } else {
            vector<int> path;
            for (int at = v; at != -1; at = parent[at]) path.push_back(at);
            reverse(path.begin(), path.end());
            for (int i = 0; i < path.size(); i++) {
                cout << path[i];
                if (i < path.size() - 1) cout << " ";
            }
            cout << endl;
        }
    }
}