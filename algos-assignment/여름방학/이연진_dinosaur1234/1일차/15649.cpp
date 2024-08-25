#include <iostream>
using namespace std;

int N, M;
int b[10];
int check[10];

void func15649(int a) {
    if (a == M) {
        for (int i = 0; i < M; i++) {
            cout << b[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = 1; i <= N; i++) {
        if (!check[i]) {
            b[a] = i;
            check[i] = 1;
            func15649(a + 1);
            check[i] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    func15649(0);
    return 0;
}
