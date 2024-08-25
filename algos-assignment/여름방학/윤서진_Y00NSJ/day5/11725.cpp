#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100001];
int parent[100001];
bool visited[100001];

void dfs(int node) {
    visited[node] = true;
    for (int next : adj[node]) {
        if (!visited[next]) {
            parent[next] = node;
            dfs(next);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    // 루트 노드 1에서 DFS 시작
    dfs(1);
    
    for (int i = 2; i <= N; i++) {
        cout << parent[i] << '\n';
    }

    return 0;
}
