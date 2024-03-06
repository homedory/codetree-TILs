#include <iostream>
using namespace std;

int N;
int board[15][15];
int flip_cnt[15][15];

void flip(int x, int y) {
    for (int i = 0; i <= x; i++) {
        for (int j = 0; j <= y; j++) {
            flip_cnt[i][j] += 1;
        }
    }
}

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            char c;
            cin >> c;
            board[i][j] = c - '0';
        }
    }

    int ans = 0;
    for (int i = N - 1; i >= 0; i--) {
        for (int j = N - 1; j >= 0; j--) {
            board[i][j] ^= ((flip_cnt[i][j] % 2 == 0) ? 0 : 1);
            if (board[i][j] == 1) {
                flip(i, j);
                ans++;
            }
        }
    }

    cout << ans;

    return 0;
}