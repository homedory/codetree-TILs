#include <iostream>
using namespace std;

int grid[105][105];
int n, m, k;

bool rowEmpty(int row) {
    for (int i = k; i < k + m; i++) {
        if (grid[row][i])
            return false;
    }
    return true;
}

int main() {
    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> grid[i][j];
        }
    }

    
    for (int row = 1; row <= n; row++) {
        if (!rowEmpty(row)) {
            for (int col = k; col < k + m; col++) {
                grid[row-1][col] = 1;
            }
            break;
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