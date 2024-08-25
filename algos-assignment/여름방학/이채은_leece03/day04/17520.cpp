#include<iostream>
using namespace std;
int n;
long long total [100001];

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int n;
	cin >> n;
	if (n % 2 == 1) {
		n++;
	}
	n /= 2;
	long long total = 1;
	for (int i = 0;i < n;i++) {
		total *= 2;
		total %= 16769023;
	}
	cout << total;
	return 0;
}
