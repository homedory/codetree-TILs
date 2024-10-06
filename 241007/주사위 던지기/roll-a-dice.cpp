#include <iostream>
using namespace std;

#define MAX_N 105

int n, m, cur_row, cur_column;
int row_order[3] = {4, 6, 3};
int column_order[3] = {5, 6, 2};
int grid[MAX_N][MAX_N];

bool inRange(int row, int col) {
    return row > 0 && row <= n && col > 0 && col <= n;
}

int moveLeft() {
    row_order[2] = row_order[1];
    row_order[1] = row_order[0];
    row_order[0] = 7 - row_order[2];
    column_order[1] = row_order[1];

    return row_order[1];
}

int moveRight() {
    row_order[0] = row_order[1];
    row_order[1] = row_order[2];
    row_order[2] = 7 - row_order[0];
    column_order[1] = row_order[1];

    return row_order[1];
}

int moveUp() {
    column_order[2] = column_order[1];
    column_order[1] = column_order[0];
    column_order[0] = 7 - column_order[2];
    row_order[1] = column_order[1];

    return column_order[1];
}

int moveDown() {
    column_order[0] = column_order[1];
    column_order[1] = column_order[2];
    column_order[2] = 7 - column_order[0];
    row_order[1] = column_order[1];

    return column_order[1];
}


int main() {
    cin >> n >> m >> cur_row >> cur_column;

    grid[cur_row][cur_column] = 6;

    for (int i = 0; i < m; i++) {
        char dir;
        int written_value = 0;
        cin >> dir;
        switch(dir) {
            case 'L': 
                if (inRange(cur_row, cur_column-1)) {
                    written_value = moveLeft();
                    cur_column--;
                }
                break;
            case 'R':
                if (inRange(cur_row, cur_column+1)) {
                    written_value = moveRight();
                    cur_column++;
                }
                break;
            case 'U':
                if (inRange(cur_row-1, cur_column)) {
                    written_value = moveUp();
                    cur_row--;
                }
                break;
            case 'D':
                if (inRange(cur_row+1, cur_column)) {
                    written_value = moveDown();
                    cur_row++;
                }
                break;
        }
        if (written_value > 0)
            grid[cur_row][cur_column] = written_value;
    }

    int sum = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            sum += grid[i][j];
        }
    }

    cout << sum;

    return 0;
}