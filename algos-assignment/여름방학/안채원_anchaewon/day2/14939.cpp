#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAX = 1000;
const int GRID_SIZE = 10;

bool input[GRID_SIZE][GRID_SIZE]; 
bool state[GRID_SIZE][GRID_SIZE]; 
bool check[GRID_SIZE][GRID_SIZE];
int next_x[4] = { -1, 0, 1, 0 };
int next_y[4] = { 0, 1, 0, -1 };
int ans = MAX;

bool checkBound(int x, int y) {
    return x >= 0 && x < GRID_SIZE && y >= 0 && y < GRID_SIZE;
}

void Click(int x, int y) {
    state[x][y] = !state[x][y];
    for (int dir = 0; dir < 4; dir++) {
        int nx = x + next_x[dir];
        int ny = y + next_y[dir];

        if (checkBound(nx, ny)) {
            state[nx][ny] = !state[nx][ny];
        }
    }
}

int simulation() {
    int cnt = 0;
    for (int i = 1; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (state[i - 1][j]) {
                cnt++;
                Click(i, j);
            }
        }
    }
    if (!memcmp(state, check, sizeof(state))) 
        return cnt;
    return MAX;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    char c;
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            cin >> c;
            if (c == 'O') 
                input[i][j] = true;
        }
    }

    for (int s = 0; s < (1 << GRID_SIZE); s++) {
        memcpy(state, input, sizeof(input));
    
        int cnt = 0;

        for (int i = 0; i < GRID_SIZE; i++) {
            if (s & (1 << i)) {
                cnt++;
                Click(0, i);
            }
        }
        cnt += simulation();

        ans = min(ans, cnt);
    }

    if (ans >= MAX) 
        cout << "-1\n";
    else 
        cout << ans << '\n';

    return 0;
}
