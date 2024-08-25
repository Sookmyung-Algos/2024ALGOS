#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    string str;
    cin >> str;
    string low = "roygbiv";
    string high = "ROYGBIV";
    bool low_flag = true, high_flag = true;
    for (int i = 0; i < 7; i++) {
        bool low_res = false, high_res = false;
        for (int j = 0; j < N; j++) {
            if (str[j] == low[i])
                low_res = true;
            if (str[j] == high[i])
                high_res = true;
        }
        if (!low_res)
            low_flag = false;
        if (!high_res)
            high_flag = false;
    }
    if (low_flag && high_flag) {
        cout << "YeS\n";
    } else if (low_flag) cout << "yes\n";
    else if (high_flag) cout << "YES\n";
    else cout << "NO!\n";
    return 0;
}
