#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 1002;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int N, K;
        cin >> N >> K;

        vector<int> time(N + 1);
        for (int i = 1; i <= N; ++i) {
            cin >> time[i];
        }

        vector<vector<int>> adj(N + 1);
        vector<int> inDegree(N + 1, 0);
        vector<int> result(N + 1, 0);
        queue<int> q;

        for (int i = 0; i < K; ++i) {
            int X, Y;
            cin >> X >> Y;
            adj[X].push_back(Y);
            inDegree[Y]++;
        }

        int W;
        cin >> W;

        for (int i = 1; i <= N; ++i) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
            result[i] = time[i];
        }

        while (!q.empty()) {
            int cur = q.front();
            q.pop();

            for (int next : adj[cur]) {
                inDegree[next]--;
                result[next] = max(result[next], result[cur] + time[next]);

                if (inDegree[next] == 0) {
                    q.push(next);
                }
            }
        }

        cout << result[W] << '\n';
    }

    return 0;
}
