#include <iostream>
using namespace std;

#define MAX_N 105

int n;
int grid[MAX_N][MAX_N];
int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0, -1, 0};

int changeDir(int cur_dir, int bar_type) {
    if ((cur_dir + bar_type) % 2 == 1) 
        return (cur_dir + 4 - 1) % 4;
    
    return (cur_dir + 1) % 4;
}

bool inRange(int row, int column) {
    return row > 0 && row <= n && column > 0 && column <= n;
}

int calculateTime(int start_row, int start_column, int dir) {
    int cur_row = start_row;
    int cur_column = start_column;
    int cur_dir = dir;

    int elapsed_time = 0;
    while(1) {
        elapsed_time++;
        cur_row += dr[cur_dir];
        cur_column += dc[cur_dir];

        if (!inRange(cur_row, cur_column))
            break;
        
        if (grid[cur_row][cur_column] == 0)
            continue;
        
        cur_dir = changeDir(cur_dir, grid[cur_row][cur_column]);
    }

    return elapsed_time;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> grid[i][j];
        }
    }

    int max_time = 0;
    for (int i = 1; i <= n; i++) {
        max_time = max(max_time, calculateTime(i, 0, 0));
        max_time = max(max_time, calculateTime(0, i, 1));
        max_time = max(max_time, calculateTime(i, n+1, 2));
        max_time = max(max_time, calculateTime(n+1, i, 3));
    }

    cout << max_time;


    return 0;
}