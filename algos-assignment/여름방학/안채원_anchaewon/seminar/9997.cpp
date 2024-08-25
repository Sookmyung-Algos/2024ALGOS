#include <iostream>
#include <string>
using namespace std;

int N, ans;
int a[25];

void solve(int idx, int mask) {
    if (idx == N) {
        if (mask == (1 << 26) - 1) ans++;
        return;
    }
    solve(idx + 1, mask);
    solve(idx + 1, mask | a[idx]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        int bitmask = 0;
        for (char c : s) bitmask |= (1 << (c - 'a'));
        a[i] = bitmask;
    }

    ans = 0;
    solve(0, 0);
    cout << ans << '\n';

    return 0;
}
