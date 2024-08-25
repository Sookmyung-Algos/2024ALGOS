#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<pair<int, int>> circles;

    for (int i = 0; i < N; ++i) {
        int x, r;
        cin >> x >> r;
        circles.emplace_back(x - r, i);
        circles.emplace_back(x + r, i);
    }

    sort(circles.begin(), circles.end());

    stack<int> stk;
    for (const auto& c : circles) {
        if (!stk.empty() && stk.top() == c.second) {
            stk.pop();
        } else {
            stk.push(c.second);
        }
    }

    if (stk.empty()) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}