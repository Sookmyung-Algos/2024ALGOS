#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

#define FASTIO ios::sync_with_stdio(false);cin.tie(NULL);
typedef long long ll;

vector<ll> x;

ll f(ll d) {

    //두 전봇대 사이의 거리가 d일 때, 이동 거리의 합
    ll ret = 0;
    for (ll i = 0; i < x.size(); i++) ret += abs(x[i] - d * i);

    return ret;
}

ll ternary_search() {

    ll l = 1, r = 1e9, lmid, rmid;

    while (l + 3 < r) {
        lmid = (l + l + r) / 3, rmid = (l + r + r) / 3;
        if (f(lmid) < f(rmid))r = rmid;
        else l = lmid;
    }

    ll ans = LLONG_MAX;
    for (ll i = l; i <= r; i++) ans = min(ans, f(i));

    return ans;
}

int main() {

    FASTIO;

    int n; cin >> n;

    x.resize(n);

    for (int i = 0; i < n; i++) cin >> x[i];

    cout << ternary_search() << "\n";

    return 0;
}
