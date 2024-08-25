#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long X;
    cin >> X;

    long long n = 1;
    long long sum = 1;

    while (X > sum) {
        n++;
        sum += n;
    }

    long long index = X - (sum - n);

    if (n % 2 == 1) {
        cout << (n - index + 1) << "/" << index << '\n';
    } else {
        cout << index << "/" << (n - index + 1) << '\n';
    }

    return 0;
}
