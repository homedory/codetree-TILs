#include <iostream>
using namespace std;

#define MAX_N 25
int n, m, t;
int grid[MAX_N][MAX_N], count[MAX_N][MAX_N], temp[MAX_N][MAX_N];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool inRange(int x, int y) {
    return x > 0 && x <= n && y > 0 && y <= n;
}

void init() {
    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= n; j++) 
            temp[i][j] = 0;
}

void copyTemp() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (count[i][j] > 1)
                continue;
            count[i][j] = temp[i][j];
        }
    }
}

void simulate() {
    init();

    for (int x = 1; x <= n; x++) {
        for (int y = 1; y <= n; y++) {
            if (count[x][y] != 1)
                continue;
            
            int next_dir = 0;
            int max_num = 0;
            for (int dir = 0; dir < 4; dir++) {
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                if (!inRange(nx, ny))
                    continue;
                
                if (grid[nx][ny] > max_num) {
                    max_num = grid[nx][ny];
                    next_dir = dir;
                }
            }

            int nx = x + dx[next_dir];
            int ny = y + dy[next_dir];
            temp[nx][ny] += 1;
        }
    }

    copyTemp();
}


int main() {
    cin >> n >> m >> t;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n ; j++) {
            cin >> grid[i][j];
        }
    }
    for (int i = 0; i < m; i++) {
        int r, c;
        cin >> r >> c;
        count[r][c] = 1;
    }

    for (int i = 0; i < t; i++) {
        simulate();
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (count[i][j] == 1)
                ans++;
        }
    }

    cout << ans;

    return 0;
}