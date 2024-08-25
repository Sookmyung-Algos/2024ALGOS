#include <iostream>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

int T, K, C;

int gcd(int x, int y) {
    return y == 0 ? x : gcd(y, x % y);
}

pii ext_gcd(int a, int b) {
    if (b) {
        pii tmp = ext_gcd(b, a % b);
        return {tmp.second, tmp.first - (a / b) * tmp.second};
    } else {
        return {1, 0};
    }
}

ll mod_inv(int a, int M) {
    return (ext_gcd(a, M).first + M) % M;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    while (T--) {
        cin >> K >> C;
        if (gcd(C, K) != 1) {
            cout << "IMPOSSIBLE" << '\n';
            continue;
        }

        ll res = mod_inv(C, K);
        while (C * res <= K) res += K;

        if (res > 1e9) cout << "IMPOSSIBLE" << '\n';
        else cout << res << '\n';
    }

    return 0;
}
