#include <iostream>
using namespace std;

#define MAX_N 22

int grid[MAX_N][MAX_N];
pair<int,int> position[MAX_N*MAX_N];
int n, m;
int dr[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dc[8] = {0, 1, 1, 1, 0, -1, -1, -1};

void swap(int r1, int c1, int r2, int c2) {
    int num1 = grid[r1][c1];
    int num2 = grid[r2][c2];

    grid[r1][c1] = num2;
    grid[r2][c2] = num1;

    position[num1] = {r2, c2};
    position[num2] = {r1, c1};
}

bool inRange(int r, int c) {
    return r > 0 && r <= n && c > 0 && c <= n;
}

void simulate(int r, int c) {
    int max_val = 0;
    int max_dir = 0;
    for (int dir = 0; dir < 8; dir++) {
        int nr = r + dr[dir];
        int nc = c + dc[dir];
        if (!inRange(nr, nc))
            continue;
        
        if (grid[nr][nc] > max_val) {
            max_val = grid[nr][nc];
            max_dir = dir;
        }
    }

    int nr = r + dr[max_dir];
    int nc = c + dc[max_dir];

    swap(r, c, nr, nc);
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> grid[i][j];
            position[grid[i][j]] = {i, j};
        }
    }

    for (int i = 0; i < m; i++) {
        for (int num = 1; num <= n*n; num++) {
            simulate(position[num].first, position[num].second);
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}