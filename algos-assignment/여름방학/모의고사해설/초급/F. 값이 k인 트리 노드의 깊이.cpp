#include <iostream>
#include <vector>
using namespace std;

// BOJ 25511 

#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL);
#define MAX 100001

vector<int> v[MAX];
vector<int> arr(MAX);
bool visit[MAX];
int n, k, ans;

void dfs(int now, int d) {
	if (visit[now]) return;
	visit[now] = true;

	if (arr[now] == k) {
		cout << d;
		exit(0);
	}

	for (int i = 0; i < v[now].size(); i++)
		dfs(v[now][i], d + 1);
}

int main() {
	FASTIO;

	cin >> n >> k;

	for (int i = 0, a, b; i < n - 1; i++) {
		cin >> a >> b;
		v[a].push_back(b);
	}

	for (int i = 0; i < n; i++)cin >> arr[i];
	dfs(0, 0);
	return 0;
}
