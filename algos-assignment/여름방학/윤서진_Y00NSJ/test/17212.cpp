#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;

    vector<int> dp(N + 1, INT_MAX);  // dp 테이블을 큰 값으로 초기화
    dp[0] = 0;  // 0원을 만들기 위한 동전 개수는 0

    int coins[] = {1, 2, 5, 7};  // 동전의 종류
    
    for (int i = 1; i <= N; i++) {
        for (int coin : coins) {
            if (i >= coin) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }

    cout << dp[N] << '\n';

    return 0;
}
