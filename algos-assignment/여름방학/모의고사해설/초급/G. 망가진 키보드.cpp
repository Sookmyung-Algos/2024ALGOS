#include <iostream>
#include <string>
#include <unordered_map>

// BOJ 6503

#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

int main() {
    FASTIO;

    int m;
    while (cin >> m && m != 0) {
        string s;
        cin.ignore();
        getline(cin, s);

        unordered_map<char, int> cnt;
        int left = 0, right = 0, ans = 0;

        while (right < s.size()) {
            cnt[s[right]]++;

            while (cnt.size() > m) {
                cnt[s[left]]--;
                if (cnt[s[left]] == 0) cnt.erase(s[left]);
                left++;
            }

            ans = max(ans, right - left + 1);
            right++;
        }
        cout << ans << "\n";
    }
    return 0;
}
