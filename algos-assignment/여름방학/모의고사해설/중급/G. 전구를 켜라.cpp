#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<pi, int> pii;
typedef pair<pi, pi> pipi;

const int MAX = 1e6 + 7;
const int MOD = 1e9 + 7;
//const int MOD = 998'244'353;
const int INF = 1e9 + 7;
int dx[] = { -1, 1, 0, 0, -1, 1, -1, 1 };
int dy[] = { 0, 0, -1, 1, -1, -1, 1, 1 };
ll dist[MAX];
vector<pi> edge[MAX];
int N, M;

int main (void) {
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);
    cout.tie (NULL);

    cin >> N >> M;
    vector<string> board(N);
    for (int i = 0; i < N; i++) {
        cin >> board[i];
        for (int j = 0; j < M; j++) {
            int cur = i * (M + 1) + j;
            int nl = (i + 1) * (M + 1) + j;
            if (board[i][j] == '/') {
                edge[cur + 1].push_back ({nl, 0});
                edge[cur].push_back ({nl + 1, 1});
                edge[nl].push_back ({cur + 1, 0});
                edge[nl + 1].push_back ({cur, 1});
            } else {
                edge[cur + 1].push_back ({nl, 1});
                edge[cur].push_back ({nl + 1, 0});
                edge[nl].push_back ({cur + 1, 1});
                edge[nl + 1].push_back ({cur, 0});
            }
        }
    }
    deque<int> dq;
    dist[0] = 1;
    dq.push_back (0);
    while (!dq.empty()) {
        int cur = dq.front();
        dq.pop_front();
        for (auto& it : edge[cur]) {
            int next = it.X;
            int weight = it.Y;
            if (!dist[next]) {
                if (weight) {
                    dq.push_back (next);
                    dist[next] = dist[cur] + 1;
                } else {
                    dq.push_front (next);
                    dist[next] = dist[cur];
                }
            }
            else {
                if (dist[cur] + weight < dist[next]) {
                    dist[next] = dist[cur] + weight;
                    if (weight) dq.push_back (next);
                    else dq.push_front (next);
                }
            }
        }
    }
    if (!dist[(N + 1) * (M + 1) - 1]) cout << "NO SOLUTION\n";
    else cout << dist[(N + 1) * (M + 1) - 1] - 1 << "\n";
    return 0;
}
