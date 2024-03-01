#include <iostream>
using namespace std;

int n, m;
int board[105][105];
bool visited[105][105];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool dfs(int x, int y, int min_h, int max_h) {
    visited[x][y] = true;

    if (x == n && y == m)
        return true;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx > 0 && nx <= n && ny > 0 && ny <= m && visited[nx][ny] == false) {
            if (board[nx][ny] >= min_h && board[nx][ny] <= max_h) {
                if (dfs(nx, ny, min_h, max_h)) {
                    return true;
                }
            }
        }
    }
    
    return false;
}

bool IsPossible(int d) {

    for (int i = 1; i + d <= 500; i++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                visited[i][j] = false;
            }
        }
        
        if (board[1][1] >= i && board[1][1] <= i + d) {
            if (dfs(1, 1, i, i + d)) {
                return true;
            }
        }
    }
    
    return false;
}

int main() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> board[i][j];
        }
    }

    int l = 0, r = 500;
    int ans;
    while(l <= r) {
        int mid = (l + r) / 2;

        if (IsPossible(mid)) {
            r = mid - 1;
            ans = mid;
        }
        else {
            l = mid + 1;
        }
    }

    cout << ans;


    return 0;
}