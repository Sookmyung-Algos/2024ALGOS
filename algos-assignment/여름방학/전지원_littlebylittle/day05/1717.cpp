#include <iostream>
#include <vector>

using namespace std;

vector<int> v; //parent

int find(int a) {
	if (v[a] == a) return a;
	else return v[a] = find(v[a]);
}

void uni(int a, int b) {
	int rootA = find(a);
	int rootB = find(b);
	if (rootA == rootB) return;
	v[rootA] = rootB;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	int c, a, b;

	v.resize(n + 1);

	for (int i = 0; i <= n; i++) {
		v[i] = i;
	}
	while (m--) {
		cin >> c >> a >> b;
		if (c == 0) {
			uni(a, b);
		}
		else {
			if (find(a) == find(b)) {
				cout << "YES" << '\n';
			}
			else {
				cout << "NO" << '\n';
			}
		}
	}
	return 0;
}
