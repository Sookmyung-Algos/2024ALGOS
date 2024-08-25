#include <bits/stdc++.h>
using namespace std;

int n, m;
int grid[300][300];
bool visited[300][300];
int dx[] = {0, 1}; // 동쪽(오른쪽)으로 이동
int dy[] = {1, 0}; // 남쪽(아래쪽)으로 이동

bool bfs() {
    queue<pair<int, int>> q;
    q.push({0, 0}); // 시작점 북서쪽 끝 (0, 0)
    visited[0][0] = true;
    
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        // 목표 지점에 도달했을 경우
        if (x == m - 1 && y == n - 1) {
            return true;
        }
        
        for (int i = 0; i < 2; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            // 도시 범위를 벗어나지 않으며, 방문하지 않은 경로 중 갈 수 있는 곳
            if (nx >= 0 && ny >= 0 && nx < m && ny < n && grid[nx][ny] == 1 && !visited[nx][ny]) {
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
    
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    if (bfs()) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }

    return 0;
}
