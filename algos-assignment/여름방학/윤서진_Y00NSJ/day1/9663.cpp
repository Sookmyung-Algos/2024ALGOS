#include <bits/stdc++.h>
using namespace std;

int n, answer = 0;
int col[15];  // 각 행에 퀸이 놓인 열의 위치를 저장

// 유효한 위치인지 확인하는 함수
bool isValid(int row) {
    for (int i = 0; i < row; i++) {
        // 같은 열에 있거나 대각선에 있는지 확인
        if (col[row] == col[i] || abs(col[row] - col[i]) == row - i)
            return false;
    }
    return true;
}

// 백트래킹 함수
void backtrack(int row) {
    if (row == n) {
        answer++;
        return;
    }
    for (int i = 0; i < n; i++) {
        col[row] = i;  // row 행에 i 열에 퀸을 놓는다.
        if (isValid(row)) {
            backtrack(row + 1);  // 다음 행으로 이동
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    backtrack(0);
    cout << answer << '\n';

    return 0;
}
