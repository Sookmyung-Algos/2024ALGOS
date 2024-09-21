#include<iostream>
using namespace std;;

int map[2187][2187];
int zero_cnt = 0, one_cnt = 0, minus_cnt = 0;

void div_conq(int x, int y, int N) {
	int z_cnt = 0, o_cnt=0, m_cnt = 0;
	for (int i = x; i < x + N; i++) {
		for (int j = y; j < y + N; j++) {
			if (map[i][j]==0) {
				z_cnt++;
			}
			else if (map[i][j] == 1) {
				o_cnt++;
			}
			else if (map[i][j] == -1) {
				m_cnt++;
			}
		}
	}
	if (o_cnt == N * N) one_cnt++;
	else if (z_cnt == N * N) zero_cnt++;
	else if (m_cnt == N * N) minus_cnt++;
	else {
		div_conq(x, y, N / 3);
		div_conq(x, y + N / 3, N / 3);
		div_conq(x + N / 3, y, N / 3);
		div_conq(x + N / 3, y + N / 3, N / 3);
		div_conq(x + N / 3 *2, y, N / 3);
		div_conq(x + N / 3 *2, y + N / 3, N / 3);
		div_conq(x + N / 3 *2, y + N / 3 *2, N / 3);
		div_conq(x, y + N / 3 *2, N / 3);
		div_conq(x + N / 3, y + N / 3 *2, N / 3);

	}
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	div_conq(0, 0, n);
	cout << minus_cnt << "\n";
	cout << zero_cnt << "\n";
	cout << one_cnt;

}
