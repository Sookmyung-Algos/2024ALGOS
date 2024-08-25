#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k;
vector<int> edge[100001];
int tree[100001];
int visited[100001];

int dfs (int node, int depth) {
    if (tree[node] == k) return depth;
    for (auto& next : edge[node]) {
        int result = dfs(next, depth + 1);
        if (result != -1) return result;
    }
    return -1;
}

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        edge[a].push_back(b);
        visited[b] = 1;
    }
    for (int i = 0; i < n; i++) cin >> tree[i];
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            int result = dfs(i, 0);
            if (result != -1) {
                cout << result << '\n';
                return 0;
            }
        }
    }
    return 0;
}
