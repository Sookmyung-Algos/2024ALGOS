#include <iostream>
using namespace std;

const long long MOD = 1000000007;

long long mod_pow(long long base, int exp, long long mod = MOD) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) 
            result = result * base % mod;
        base = base * base % mod;
        exp /= 2;
    }
    return result;
}

long long mod_inv(int n, long long mod = MOD) {
    return mod_pow(n, mod - 2, mod);
}

long long comb(int n, int r, long long mod = MOD) {
    if (r > n) return 0;
    long long num = 1, denom = 1;
    for (int i = 0; i < r; ++i) {
        num = num * (n - i) % mod;
        denom = denom * (i + 1) % mod;
    }
    return num * mod_inv(denom, mod) % mod;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, r;
    cin >> n >> r;
    cout << comb(n, r) << '\n';

    return 0;
}
