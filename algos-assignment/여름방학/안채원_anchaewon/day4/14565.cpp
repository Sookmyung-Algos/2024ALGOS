#include <iostream>
using namespace std;

long long Euclid(long long a, long long b, long long &s, long long &t) {
	if (b == 0) {s = 1; t = 0; return a;}
	long long gcd = Euclid(b, a%b, s, t);
	long long x = t;
	t = s - (a / b)*t; s = x;
	if (s <= 0) {s += b; t -= a;}
	return gcd;
}

int main(void) {
	long long n, a, c, k; cin >> n >> a;
	long long g = Euclid(a, n, c, k);
	if (g != 1) cout << n - a << ' ' << -1;
	else cout << n - a << ' ' << c;
}