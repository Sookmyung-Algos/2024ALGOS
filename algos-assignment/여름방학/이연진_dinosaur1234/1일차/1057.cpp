#include <iostream>
using namespace std;

int main() {
    int N, j, h;
    int round = 0;
    cin >> N >> j >> h;

    while (j != h) {
        j = (j + 1) / 2; 
        h = (h + 1) / 2; 
        round++; 
    }

    cout << round << endl;

    return 0;
}
