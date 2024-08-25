#include <bits/stdc++.h>
using namespace std;

const int MOD = 16769023;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    dp[0][0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= i; j++) {
            if (j > 0) {
                dp[i][j] = dp[i-1][j-1]; // 0을 추가
            }
            if (j < i) {
                dp[i][j] = (dp[i][j] + dp[i-1][j+1]) % MOD; // 1을 추가
            }
        }
    }

    // 길이가 n인 모든 균형잡힌 문자열의 수를 구함
    int result = 0;
    for (int j = 0; j <= n; j++) {
        result = (result + dp[n][j]) % MOD;
    }

    cout << result << endl;

    return 0;
}
