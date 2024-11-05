#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<pair<int, int>>line;
vector<int>dp(501);

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int from, to;
		cin >> from >> to;
		line.push_back(make_pair(from, to));
	}

	sort(line.begin(), line.end());


	int answer = 1;
	for (int i = 0; i < n; i++) {
		dp[i] = 1;
	}
	for (int i = 1; i < n; i++) {
		for (int j = i-1; j >=0; j--) {
			if (line[j].second < line[i].second) {
				dp[i] = dp[i] > dp[j] + 1 ? dp[i] : dp[j] + 1;
			}
		}
		answer = dp[i] > answer ? dp[i] : answer;
	}

	cout << n - answer;

	return 0;
}
