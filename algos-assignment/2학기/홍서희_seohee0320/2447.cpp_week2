#include<iostream>
using namespace std;;

int star(int x, int y, int N) {
	if ((x / N) % 3 == 1 && (y / N) % 3 == 1) {
		cout << " ";
	}
	else {
		if (N / 3 == 0) {
			cout << "*";
		}
		else {
			star(x, y, N / 3);
		}
	}

	return 0;

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			star(i, j, n);
		}
		cout << "\n";
	}
}
