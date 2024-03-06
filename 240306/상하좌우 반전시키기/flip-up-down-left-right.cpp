#include <iostream>
using namespace std;

int board[105][105];
int n;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void flip(int x, int y) {

    board[x][y] ^= 1;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
            board[nx][ny] ^= 1;
        }
    }
}

int main() {

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    int ans = 0;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 0) {
                flip(i + 1, j);
                ans++;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (board[n - 1][i] == 0) {
            cout << -1;
            return 0;
        }
    }

    cout << ans;
    
    return 0;
}