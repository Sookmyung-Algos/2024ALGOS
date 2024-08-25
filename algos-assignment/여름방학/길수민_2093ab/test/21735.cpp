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
int N, M;
int arr[MAX];
int ans = 0;

void backtrack (int cur, int step, int pos) {
    if (step == M || pos == N) {
        ans = max (ans, cur);
        return;
    }
    backtrack (cur + arr[pos + 1], step + 1, pos + 1);
    if (pos + 2 <= N)
        backtrack (cur / 2 + arr[pos + 2], step + 1, pos + 2);
}

int main (void)
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);
    cout.tie (NULL);

    cin >> N >> M;
    for (int i = 1; i <= N; i++) cin >> arr[i];
    backtrack (1, 0, 0);
    cout << ans << "\n";
    return 0;
}
