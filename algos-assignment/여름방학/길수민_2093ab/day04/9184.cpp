#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<pi, int> pii;
typedef pair<pi, pi> pipi;

const int MAX = 1e6 + 7;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 7;
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
int dp[111][111][111];

int solve (int a, int b, int c)
{
    if (a <= 0 || b <= 0 || c <= 0)
        return 1;
    if (dp[a][b][c]) return dp[a][b][c];
    if (a > 20 || b > 20 || c > 20)
        return dp[a][b][c] = solve (20, 20, 20);
    if (a < b && b < c)
        return dp[a][b][c] = solve (a, b, c - 1) + solve (a, b - 1, c - 1) - solve (a, b - 1, c);
    return dp[a][b][c] = solve (a - 1, b, c) + solve (a - 1, b - 1, c) + solve (a - 1, b, c - 1) - solve (a - 1, b - 1, c - 1);
}

int main (void)
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);
    cout.tie (NULL);

    while (true) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == -1 && b == -1 && c == -1) break;
        int ans = solve (a, b, c);
        cout << "w(" << a << ", " << b << ", " << c << ") = " << ans << "\n";
    }
    return 0;
}
