#include <iostream>
#include <queue>
using namespace std;

int main() {
    int M, N;
    cin >> M >> N;

    int box[1000][1000];
    int day[1000][1000] = {0};
    queue<pair<int, int>> q;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> box[i][j];
            if (box[i][j] == 1) {
                q.push(make_pair(i, j));
            }
        }
    }

    //이전 코드보다 단순화(가로세로 이동)
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int x1 = x + dx[i];
            int y1 = y + dy[i];

            if (x1 >= 0 && x1 < N && y1 >= 0 && y1 < M) {
                if (box[x1][y1] == 0) {
                    box[x1][y1] = 1;
                    q.push(make_pair(x1, y1));
                    day[x1][y1] = day[x][y] + 1;
                }
            }
        }
    }

    int max = 0;
    bool b = true;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (box[i][j] == 0) {
                b = false;
            }
            if (day[i][j] > max) {
                max = day[i][j];
            }
        }
    }

    if (b) {
        cout << max << '\n';
    } else {
        cout << -1 << '\n';
    }

    return 0;
}
