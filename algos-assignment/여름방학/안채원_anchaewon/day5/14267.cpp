#include <iostream>
#include <vector>

using namespace std;

const int MAX = 100005;

vector<int> adj[MAX];
int parent[MAX];
int dp[MAX];

void dfs(int node, int parent_node) {
    for (int child : adj[node]) {
        if (child == parent_node) continue;
        dp[child] += dp[node];
        dfs(child, node);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    fill(parent, parent + N + 1, -1);
    fill(dp, dp + N + 1, 0);

    for (int i = 1; i <= N; i++) {
        int num;
        cin >> num;
        parent[i] = num;
        if (num != -1) {
            adj[num].push_back(i);
            adj[i].push_back(num);
        }
    }

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        dp[a] += b;
    }

    dfs(1, -1);

    for (int i = 1; i <= N; i++) {
        cout << dp[i] << " ";
    }
    cout << '\n';

    return 0;
}
