#include<iostream>
using namespace std;;

int map[129][129];
int white = 0, blue = 0;

void div_conq(int x, int y, int N) {
	for (int i = x; i < x + N; i++) {
		for (int j = y; j < y + N; j++) {
			if (map[i][j] != map[x][y]) {
				div_conq(x, y, N / 2);
				div_conq(x, y + N / 2, N / 2);
				div_conq(x + N / 2, y, N / 2);
				div_conq(x + N / 2, y + N / 2, N / 2);
				return;
			}
		}
	}
	if (map[x][y] == 0) white++;
	else blue++;
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
	cout << white << "\n";
	cout << blue;

	return 0;
}
