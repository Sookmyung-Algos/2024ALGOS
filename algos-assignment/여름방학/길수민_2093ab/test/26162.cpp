#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool is_prime(int x) {
    if (x < 2) return false;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

void solve() {
    int a;
    cin >> a;
    for (int i = 2; i < a; i++) {
        if (i > a - i) break;
        if (is_prime(i) && is_prime(a - i)) {
            cout << "Yes\n";
            return;
        }
    }
    cout << "No\n";
}

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}
