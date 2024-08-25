#include <iostream>
using namespace std;

// BOJ 26162

#define MAX 130
#define FASTIO ios::sync_with_stdio(false);cin.tie(NULL);

bool nPrime[MAX] = { true, true };

int main()
{
	FASTIO;
	int n, a, k;	
	cin >> n;

	for (int i = 2; i * i <= MAX; i++) {
		if (nPrime[i]) continue;
		else for (int j = i + i; j < MAX; j += i) nPrime[j] = true;
	}

	while (n--) {
		cin >> a;
		for (k = 1; k < a; k++)
			if (!nPrime[k] && !nPrime[a - k])
				break;

		if (k == a) cout << "No\n";
		else cout << "Yes\n";
	}
	return 0;
}
