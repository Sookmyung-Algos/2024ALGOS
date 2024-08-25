#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;  // 무한대를 나타내기 위해 큰 값 설정

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> dist(n + 1, vector<int>(n + 1, INF));
    
    // 자기 자신으로 가는 비용은 0으로 초기화
    for (int i = 1; i <= n; i++) {
        dist[i][i] = 0;
    }
    
    // 버스 정보 입력 받아 초기화
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        dist[a][b] = min(dist[a][b], c);  // 같은 경로의 다른 버스가 있을 수 있으므로 최소값 저장
    }
    
    // 플로이드-워셜 알고리즘
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    
    // 결과 출력
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dist[i][j] == INF) {
                cout << "0 ";
            } else {
                cout << dist[i][j] << " ";
            }
        }
        cout << '\n';
    }

    return 0;
}
