#include<iostream>
using namespace std;;

char map[65][65];

void div_conq(int x, int y, int N) {
	int tmp_cnt = 0;
	for (int i = x; i < x + N; i++) {
		for (int j = y; j < y + N; j++) {
			if (map[i][j]=='1') {
				tmp_cnt++;
			}
		}
	}
	if (!tmp_cnt) {
		cout << "0";
	}
	else if (tmp_cnt == N * N) {
		cout << "1";
	}
	else {
		cout << "(";
		div_conq(x, y, N / 2);
		div_conq(x, y + N / 2, N / 2);
		div_conq(x + N / 2, y, N / 2);
		div_conq(x + N / 2, y + N / 2, N / 2);
		cout << ")";
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

}
