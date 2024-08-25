#include <iostream>
using namespace std;

// BOJ 17212

#define FASTIO ios::sync_with_stdio(false);cin.tie(NULL);
#define MAX 1000001
int dp[MAX], n;

int main()
{
	FASTIO;

	cin >> n;
	dp[1] = 1, dp[2] = 1, dp[3] = 2, dp[4] = 2, dp[5] = 1, dp[6] = 2, dp[7] = 1;

	for (int i = 8; i <= n; i++)
	{
		if (i % 7 == 0) dp[i] = i / 7;
		else dp[i] = min(min(min(dp[i - 1], dp[i - 2]), dp[i - 5]), dp[i - 7]) + 1;
	}
	cout << dp[n];
	return 0;
}
