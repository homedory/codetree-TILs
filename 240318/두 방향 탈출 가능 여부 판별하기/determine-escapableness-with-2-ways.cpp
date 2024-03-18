#include <iostream>
using namespace std;

#define MAX_N 105

bool visited[MAX_N][MAX_N];
int board[MAX_N][MAX_N];
int n, m;

bool canGo(int x, int y) {
    if (x > 0 && x <= n && y > 0 && y <= m && board[x][y] == 1) 
        return true;
    
    return false;
}

void dfs(int x, int y) {
    int dx[2] = {1, 0};
    int dy[2] = {0, 1};

    for (int i = 0; i < 2; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (canGo(nx, ny) && !visited[nx][ny]) {
            visited[nx][ny] = true;
            dfs(nx, ny);
        }
    }
}

int main() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> board[i][j];
        }
    }

    if (canGo(1,1)) {
        visited[1][1] = true;
        dfs(1, 1);
    }
    
    if (visited[n][m])
        cout << 1;
    else
        cout << 0;

    return 0;
}