#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define MOD 16769023

using namespace std;

int main (void)
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);
    cout.tie (NULL);
    int n;
    cin >> n;
    vector<int> dp(n + 1, 2);
    for (int i = 3; i <= n; i++)
    {
        if (i % 2) dp[i] = (dp[i - 1] * 2) % MOD;
        else dp[i] = dp[i - 1];
    }
    cout << dp[n] << "\n";
    return 0;
}
