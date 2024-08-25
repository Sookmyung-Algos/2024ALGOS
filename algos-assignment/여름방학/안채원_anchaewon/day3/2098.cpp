#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int INF = 1e8;
int dp[1 << 16][20];
int w[20][20];

int main() {
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> w[i][j];

    for (int i = 0; i < (1 << n); i++)
        for (int j = 0; j < n; j++)
            dp[i][j] = INF;

    for (int i = 0; i < n; i++) 
        if (w[0][i]) 
            dp[1 << i][i] = w[0][i];

    for (int state = 1; state < (1 << n); state++) {
        for (int i = 0; i < n; i++) {
            if (!(state & (1 << i))) continue;
            for (int j = 0; j < n; j++) {
                if (!(state & (1 << j))) continue;
                if (w[i][j]) 
                    dp[state][j] = min(dp[state][j], dp[state & ~(1 << j)][i] + w[i][j]);
            }
        }
    }

    cout << dp[(1 << n) - 1][0];
    return 0;
}
