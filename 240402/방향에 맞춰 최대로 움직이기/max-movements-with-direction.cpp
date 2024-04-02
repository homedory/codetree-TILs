#include <iostream>
using namespace std;

#define MAX_N 5

int N;
int board[MAX_N][MAX_N], direction[MAX_N][MAX_N];
int dr[9] = {0, -1, -1, 0, 1, 1, 1, 0, -1};
int dc[9] = {0, 0, 1, 1, 1, 0, -1, -1, -1};
int max_cnt = 0;

bool inRange(int x, int y) {
    return x > 0 && x <= N && y > 0 && y <= N;
}

bool canGo(int x, int y, int prev_num) {
    if (board[x][y] <= prev_num)
        return false;
    
    return true;
}

void move(int curr_r, int curr_c, int count) {
    max_cnt = max(max_cnt, count);

    int curr_dr = dr[direction[curr_r][curr_c]];
    int curr_dc = dc[direction[curr_r][curr_c]];

    int next_r = curr_r + curr_dr;
    int next_c = curr_c + curr_dc;

    while(inRange(next_r, next_c)) {
        if (canGo(next_r, next_c, board[curr_r][curr_c])) {
            move(next_r, next_c, count + 1);
        }
        next_r += curr_dr;
        next_c += curr_dc;
    }
}

int main() {
    int r, c;

    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> direction[i][j];
        }
    }

    cin >> r >> c;

    move(r, c, 0);

    cout << max_cnt;

    return 0;
}