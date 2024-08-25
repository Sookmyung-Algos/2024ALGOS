#include <iostream>
#include <vector>

using namespace std;

const int MAX_SIZE = 1 << 21;

int k, last;
vector<int> a(MAX_SIZE);
long long ans;

int solve(int n) {
    if ((1 << k) - 1 <= n && n < last) 
        return 0;
    
    int left = solve(n * 2 + 1);
    int right = solve(n * 2 + 2);
    
    if (a[n * 2 + 1] + left < a[n * 2 + 2] + right) 
        a[n * 2 + 1] = a[n * 2 + 2] + right - left;
    else 
        a[n * 2 + 2] = a[n * 2 + 1] + left - right;
    
    ans += a[n * 2 + 2] + a[n * 2 + 1];
    return left + a[n * 2 + 1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> k;
    last = (1 << (k + 1)) - 1;
    
    for (int i = 1; i < last; i++) 
        cin >> a[i];
    
    solve(0);
    cout << ans << '\n';
    
    return 0;
}
