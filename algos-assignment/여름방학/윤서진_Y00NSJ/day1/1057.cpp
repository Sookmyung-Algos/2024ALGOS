#include <iostream>
using namespace std;

int main() {
    int N, jimin, hansu;
    cin >> N >> jimin >> hansu;
    
    int round = 0;

    // 반복적으로 번호를 갱신하며 두 번호가 같아질 때까지 진행
    while (jimin != hansu) {
        jimin = (jimin + 1) / 2;
        hansu = (hansu + 1) / 2;
        round++;
    }

    cout << round << '\n';

    return 0;
}
