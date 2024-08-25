#include <iostream>
#include <queue>
using namespace std;

// BOJ 31575
 
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL);
#define MAX 301

int n, m, arr[MAX][MAX];
int dx[2] = { 1, 0 }, dy[2] = { 0, 1 };
bool visit[MAX][MAX];

bool bfs()
{
	queue<pair<int, int>> q;
	q.push({ 0, 0 });
	visit[0][0] = true;

	while (!q.empty())
	{
		int x = q.front().second;
		int y = q.front().first;
		q.pop();

		for (int i = 0; i < 2; i++)
		{
			int gx = x + dx[i];
			int gy = y + dy[i];

			if (gx >= 0 && gx < n && gy >= 0 && gy < m && !visit[gy][gx] && arr[gy][gx] == 1) {
				visit[gy][gx] = true;
				q.push({ gy, gx });
			}
		}
	}
	return visit[m - 1][n - 1];
}

int main() {
	FASTIO;

	cin >> n >> m;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];

	if (bfs()) cout << "Yes";
	else cout << "No";
	return 0;
}
