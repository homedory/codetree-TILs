#include <iostream>
using namespace std;

int grid[205][205];
int n;

void explode(int column) {
    int row = 1;
    while(row < n && grid[row][column] == 0) {
        row++;
    }


    int range = grid[row][column] - 1;

    if (range < 0)
        return;

    grid[row][column] = 0;

    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    for (int r = 1; r <= range; r++) {
        for (int i = 0; i < 4; i++) {
            int nrow = row + r * dr[i];
            int ncoloumn = column + r * dc[i];
            
            if (nrow < 1 || nrow > n || ncoloumn < 1 || ncoloumn > n)
                continue;
            
            grid[nrow][ncoloumn] = 0;
        }
    }
}

void drop() {
    for (int col = 1; col <= n; col++) {
        int index = n;
        for (int row = n; row > 0; row--) {
            int temp = grid[row][col];
            
            grid[row][col] = 0;
            grid[index][col] = temp;
            
            if (temp != 0)
                index--;
        }
    }
}

int main() {
    int m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < m; i++) {
        int column;
        cin >> column;
        explode(column);
        drop();
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }


    return 0;
}