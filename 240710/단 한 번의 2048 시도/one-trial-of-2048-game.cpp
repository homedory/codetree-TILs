#include <iostream>
using namespace std;

int grid[4][4];

void left_combine() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i][j] == grid[i][j+1]) {
                grid[i][j] = 2 * grid[i][j];
                grid[i][j+1] = 0;
            }
        }
    }
}

void right_combine() {
    for (int i = 0; i < 4; i++) {
        for (int j = 3; j > 0; j--) {
            if (grid[i][j] == grid[i][j-1]) {
                grid[i][j] = 2 * grid[i][j];
                grid[i][j-1] = 0;
            }
        }
    }
}

void up_combine() {
    for (int j = 0; j < 4; j++) {
        for (int i = 0; i < 3; i++) {
            if (grid[i][j] == grid[i+1][j]) {
                grid[i][j] = 2 * grid[i][j];
                grid[i+1][j] = 0;
            }
        }
    }
}

void down_combine() {
    for (int j = 0; j < 4; j++) {
        for (int i = 3; i > 0; i--) {
            if (grid[i][j] == grid[i-1][j]) {
                grid[i][j] = 2 * grid[i][j];
                grid[i-1][j] = 0;
            }
        }
    }
}

void left_shift() {
    for (int i = 0; i < 4; i++) {
        int idx = 0;
        for (int j = 0; j < 4; j++) {
            int temp = grid[i][j];
            grid[i][j] = 0;

            if (temp != 0) {
                grid[i][idx] = temp;
                idx++;
            }
        }
    }
}

void right_shift() {
    for (int i = 0; i < 4; i++) {
        int idx = 3;
        for (int j = 3; j >= 0; j--) {
            int temp = grid[i][j];
            grid[i][j] = 0;

            if (temp != 0) {
                grid[i][idx] = temp;
                idx--;
            }
        }
    }
}

void up_shift() {
    for (int j = 0; j < 4; j++) {
        int idx = 0;
        for (int i = 0; i < 4; i++) {
            int temp = grid[i][j];
            grid[i][j] = 0;

            if (temp != 0) {
                grid[idx][j] = temp;
                idx++;
            }

        }
    }
}

void down_shift() {
    for (int j = 0; j < 4; j++) {
        int idx = 3;
        for (int i = 3; i >= 0; i--) {
            int temp = grid[i][j];
            grid[i][j] = 0;

            if (temp != 0) {
                grid[idx][j] = temp;
                idx--;
            }

        }
    }
}

int main() {
    char dir;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> grid[i][j];
        }
    }
    cin >> dir;

    switch(dir) {
        case 'L':
            left_combine();
            left_shift();
            break;
        case 'R':
            right_combine();
            right_shift();
            break;
        case 'U':
            up_combine();
            up_shift();
            break;
        case 'D':
            down_combine();
            down_shift();
            break;
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }


    return 0;
}