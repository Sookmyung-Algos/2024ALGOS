#include <iostream>
using namespace std;

// BOJ 21735

#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL);
#define MAX 101
int n, m, arr[MAX], ans;

void backTracking(int cnt, int sum, int idx) {
	if (cnt == m || idx == n - 1) ans = max(sum, ans);
	else {
		backTracking(cnt + 1, sum + arr[idx + 1], idx + 1);
		backTracking(cnt + 1, sum / 2 + arr[idx + 2], idx + 2);
	}
}

int main() 
{
	FASTIO;
	
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> arr[i];

	backTracking(0, 1, -1);
	cout << ans;
	return 0;
}
