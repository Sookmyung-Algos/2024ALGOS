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
pi arr[10];

int main (void)
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);
    cout.tie (NULL);

    int N, A, B;
    cin >> N >> A >> B;
    for (int i = 0; i < 10; i++) cin >> arr[i].X >> arr[i].Y;
    for (int i = 0; i + N < 8; i++) {
        int x = arr[i].X;
        int y = min (6 - x, arr[i].Y);
        A += x * 3;
        B += x * 3 + y * 3;
    }
    if (A >= 66 && B >= 130) cout << "Nice\n";
    else cout << "Nae ga wae\n";
    return 0;
}
