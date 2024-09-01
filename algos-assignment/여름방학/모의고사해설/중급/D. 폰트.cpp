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
int N;
vector<int> num;
int ans;

void backtrack (int step, int cur)
{
    if (step == N)
    {
        if (cur == (1 << 26) - 1) ans++;
        return;
    }
    backtrack (step + 1, cur);
    backtrack (step + 1, cur | num[step]);
}

int main (void)
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);
    cout.tie (NULL);

    cin >> N;
    num.assign (N, 0);
    for (int i = 0; i < N; i++)
    {
        string str;
        cin >> str;
        for (auto& c : str)
            num[i] = num[i] | (1 << (c - 'a'));
    }
    backtrack(0, 0);
    cout << ans << "\n";
    return 0;
}
