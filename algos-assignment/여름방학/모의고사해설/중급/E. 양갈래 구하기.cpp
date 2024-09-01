#include <iostream>
#include <vector>
#include <algorithm>
#define X first
#define Y second

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;

int N;
vector<pi> edges[100001];
bool visited[100001];

ll dfs (int node) {
    visited[node] = true;
    ll ret = 0;
    for (auto edge : edges[node]) {
        if (visited[edge.X]) continue;
        ll temp = dfs(edge.X);
        if (temp == 0) ret += edge.Y * 1LL;
        else ret += min (temp, edge.Y * 1LL);
    }
    return ret;
}

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 1; i < N; i++) {
        int a, b, v;
        cin >> a >> b >> v;
        edges[a].push_back({b, v});
        edges[b].push_back({a, v});
    }
    cout << dfs(1) << '\n';
    return 0;
}
