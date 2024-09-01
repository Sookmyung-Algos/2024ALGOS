#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<pi, int> pii;
typedef pair<pi, pi> pipi;

const int MAX = 1e5 + 7;
const int MOD = 1e9 + 7;
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
int N;
vector<vector<int>> edge;
vector<int> degree;
vector<int> cnt;
bool visited[MAX];

int main (void)
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);
    cout.tie (NULL);

    cin >> N;
    edge.resize (N);
    degree.assign (N, 0);
    cnt.assign (N, 0);
    for (int i = 0; i < N - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        degree[a]++;
        degree[b]++;
        edge[a].push_back (b);
        edge[b].push_back (a);
    }

    queue<int> q;
    for (int i = 0; i < N; i++)
    {
        cnt[degree[i]]++;
        if (degree[i] == 1) q.push(i);
    }
    int all = N;
    while (!(cnt[1] == 2 && cnt[2] == all - 2) && all != 1) {
        queue<int> new_node;
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            visited[cur] = true;
            all--;
            for (auto& node : edge[cur]) {
                if (!visited[node]) {
                    cnt[degree[node]]--;
                    cnt[degree[cur]]--;
                    degree[node]--;
                    degree[cur]--;
                    cnt[degree[node]]++;
                    cnt[degree[cur]]++;
                    if (degree[node] == 1) {
                        new_node.push (node);
                    }
                }
            }
        }
        while (!new_node.empty()) {
            q.push (new_node.front());
            new_node.pop();
        }
    }
    for (int i = 0; i < N; i++) {
        if (!visited[i]) cout << i << " ";
    }
    cout << "\n";
    return 0;
}
