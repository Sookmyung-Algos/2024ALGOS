#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, M;
    cin >> N >> M;
    
    vector<int> a(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
    }
    
    vector<vector<int>> dp(N + 1, vector<int>(M + 1, 0));
    dp[0][M] = 1; // 시작점의 눈덩이 크기는 1

    for (int i = 0; i < N; i++) {
        for (int j = M; j > 0; j--) {
            // 굴리기 (i -> i + 1)
            if (i + 1 <= N) {
                dp[i + 1][j - 1] = max(dp[i + 1][j - 1], dp[i][j] + a[i + 1]);
            }
            // 던지기 (i -> i + 2)
            if (i + 2 <= N) {
                dp[i + 2][j - 1] = max(dp[i + 2][j - 1], dp[i][j] / 2 + a[i + 2]);
            }
        }
    }

    // 최종 결과 찾기
    int result = 0;
    for (int j = 0; j <= M; j++) {
        result = max(result, dp[N][j]);
    }
    
    cout << result << '\n';

    return 0;
}
