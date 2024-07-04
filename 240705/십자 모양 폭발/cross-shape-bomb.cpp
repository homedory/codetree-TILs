#include <iostream>
using namespace std;

int grid[105][105];
int n;

void explode(int row, int col) {
    int radius = grid[row][col] - 1;

    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};
    
    grid[row][col] = 0;
    for (int i = 1; i <= radius; i++) {
        for (int j = 0; j < 4; j++) {
            int nr = row + dr[j] * i;
            int nc = col + dc[j] * i;

            if (nr < 1 || nr > n || nc < 1 || nc > n)
                continue;
            
            grid[nr][nc] = 0;
        }
    }
}

void drop() {
    for (int col = 1; col <= n; col++) {
        int temp[105];

        int temp_pos = n;

        for (int row = n; row > 0; row--) {
            if (grid[row][col] == 0)
                continue;
            
            temp[temp_pos--] = grid[row][col];
        }

        for (int row = 1; row <= temp_pos; row++)
            grid[row][col] = 0;

        for (int row = temp_pos + 1; row <= n; row++) 
            grid[row][col] = temp[row];
            
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> grid[i][j];
        }
    }

    int r, c;
    cin >> r >> c;
    explode(r, c);
    drop();

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}