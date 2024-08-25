#include <iostream>
using namespace std;

// BOJ 30403

int main() {
	int n, upper[7] = { 0, }, lower[7] = { 0, }, cnt[14] = { 0, };
	char alpha[14] = { 'R', 'O', 'Y', 'G', 'B', 'I','V', 'r','o', 'y', 'g','b', 'i','v' };
	bool upperCase = true, lowerCase = true;
	string str;
	cin >> n >> str;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 14; j++) {
			if (alpha[j] == str[i]) {
				cnt[j]++;
				break;
			}
		}
	}

	for (int i = 0; i < 14; i++) {
		if (cnt[i] == 0) {
			if (i < 7) upperCase = false;
			else lowerCase = false;
		}
	}

	if (upperCase && lowerCase) cout << "YeS";
	else if (upperCase) cout << "YES";
	else if (lowerCase) cout << "yes";
	else cout << "NO!";
	return 0;
}
