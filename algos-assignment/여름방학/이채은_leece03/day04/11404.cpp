#include<iostream>

const int INF = 10000000000000000;
int dist[101][101];

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) {
                dist[i][j] = 0;
            }
            else {
                dist[i][j] = INF;
            }
        }
    }


    for (int i = 1; i <= m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        dist[a][b] = min(dist[a][b], c); 
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dist[i][j] == INF) {
                cout << "0 ";
            }
            else {
                cout << dist[i][j] << " ";
            }
        }
        cout << "\n";
    }

    return 0;
}
