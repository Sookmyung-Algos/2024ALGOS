#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll x;
    cin >> x;
    ll left = 1, right = 1e10;

    while (left <= right) {
        ll mid = (left + right) / 2;
        ll sum = mid * (mid + 1) / 2;
        if (sum >= x) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    ll row = left;
    ll col = x - row * (row - 1) / 2;
    if (row % 2 == 0) {
        cout << col << "/" << row - col + 1 << '\n';
    } else {
        cout << row - col + 1 << "/" << col << '\n';
    }
    return 0;
}
