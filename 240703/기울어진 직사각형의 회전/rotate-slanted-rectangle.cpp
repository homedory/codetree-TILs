#include <iostream>
using namespace std;

int grid[105][105];

void shift_upper_right(int start_row, int start_col, int len) {
    for (int i = len; i > 0; i--) {
        grid[start_row-i][start_col+i] = grid[start_row-(i-1)][start_col+i-1];
    }
}

void shift_lower_right(int start_row, int start_col, int len) {
    for (int i = len; i > 0; i--) {
        grid[start_row+i][start_col+i] = grid[start_row+(i-1)][start_col+(i-1)];
    }
}

void shift_upper_left(int start_row, int start_col, int len) {
    for (int i = len; i > 0; i--) {
        grid[start_row-i][start_col-i] = grid[start_row-(i-1)][start_col-(i-1)];
    }
}

void shift_lower_left(int start_row, int start_col, int len) {
    for (int i = len; i > 0; i--) {
        grid[start_row+i][start_col-i] = grid[start_row+(i-1)][start_col-(i-1)];
    }
}

int main() {
    int n;
    int r, c, m1, m2, m3, m4, dir;

    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> grid[i][j];
        }
    }

    cin >> r >> c >> m1 >> m2 >> m3 >> m4 >> dir;

    // counter-clockwise
    if (dir == 0) {
        int tmp = grid[r-m1][c+m1];
        shift_upper_right(r, c, m1);
        shift_lower_right(r - m4, c - m4, m4);
        shift_lower_left(r - m4 - m3, c - m4 + m3, m3);
        shift_upper_left(r - m1 - 1, c + m1 - 1, m2 - 1);
        grid[r-m1-1][c+m1-1] = tmp;
    }
    // clockwise
    else {
        int tmp = grid[r-m4][c-m4];
        shift_upper_left(r, c, m4);
        shift_lower_left(r - m1, c + m1, m1);
        shift_lower_right(r - m1 - m2, c + m1 - m2, m2);
        shift_upper_right(r - m4 - 1, c - m4 + 1, m3 - 1);
        grid[r-m4-1][c-m4+1] = tmp;
    }

    // answer
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}