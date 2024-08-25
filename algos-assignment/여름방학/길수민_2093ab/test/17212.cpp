#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[100001];
int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    dp[0] = 0;
    int coin[] = {1, 2, 5, 7};

    for (int i = 1; i <= N; i++) {
        dp[i] = 100000;
        for (int j = 0; j < 4; j++) {
            if (i - coin[j] >= 0) {
                dp[i] = min(dp[i], dp[i - coin[j]] + 1);
            }
        }
    }
    cout << dp[N] << endl;
    return 0;
}
