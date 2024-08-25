#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N >> M;

    int table[1025][1025] = {0};
    int total[1025][1025] = {0};

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> table[i][j];
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            total[i][j] = table[i][j] + total[i-1][j] + total[i][j-1] - total[i-1][j-1];
        }
    }

    for (int i = 0; i < M; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        int answer = total[x2][y2] - total[x1-1][y2] - total[x2][y1-1] + total[x1-1][y1-1];
        cout << answer << '\n';
    }

    return 0;
}
