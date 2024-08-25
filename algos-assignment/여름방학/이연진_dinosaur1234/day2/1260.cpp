#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    int N, M, V;
    cin >> N >> M >> V;

    vector<vector<int>> adj(N + 1, vector<int>(N + 1, 0));
    vector<bool> visited(N + 1, false);
    vector<int> dfs, bfs;
    
    vector<int> s; //DFS
    queue<int> q; //BFS

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    // DFS 
    s.push_back(V);

    while (!s.empty()) {
        int cur = s.back();
        s.pop_back();

        if (!visited[cur]) {
            visited[cur] = true;
            dfs.push_back(cur);

            for (int i = N; i >= 1; i--) {
                if (adj[cur][i] && !visited[i]) {
                    s.push_back(i);
                }
            }
        }
    }

    fill(visited.begin(), visited.end(), false);

    // BFS 
    q.push(V);
    visited[V] = true;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        bfs.push_back(cur);

        for (int i = 1; i <= N; i++) {
            if (adj[cur][i] && !visited[i]) {
                q.push(i);
                visited[i] = true;
            }
        }
    }

    for (int i = 0; i < dfs.size(); i++) {
        cout << dfs[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < bfs.size(); i++) {
        cout << bfs[i] << " ";
    }
    cout << endl;

    return 0;
}
