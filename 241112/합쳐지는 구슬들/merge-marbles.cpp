#include <iostream>
#include <tuple>
using namespace std;

#define MAX_N 55

int n, m, t;
int grid[MAX_N][MAX_N];
pair<int,int> position[MAX_N];
int weight[MAX_N];
char direction[MAX_N];
bool removed[MAX_N];
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, 1, -1};

int getDirectionIndex(char dir) {
    if (dir == 'U') {
        return 0;
    }
    else if (dir == 'D') {
        return 1;
    }
    else if (dir == 'R') {
        return 2;
    }
    else {
        return 3;
    }
}

bool inRange(int row, int col) {
    return row > 0 && row <= n && col > 0 && col <= n;
}

void changeDirection(int num) {
    char dir = direction[num];

    if (dir == 'U') {
        direction[num] = 'D';
    }
    else if (dir == 'D') {
        direction[num] = 'U';
    }
    else if (dir == 'R') {
        direction[num] = 'L';
    }
    else {
        direction[num] = 'R';
    }
}

void clearGrid() {
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            grid[i][j] = 0;
}

void move(int num) {
    int row, col;
    tie(row, col) = position[num];

    int direction_idx = getDirectionIndex(direction[num]);
    int next_row = row + dr[direction_idx];
    int next_col = col + dc[direction_idx];

    if (!inRange(next_row, next_col)) {
        changeDirection(num);
        next_row = row;
        next_col = col;
    }

    position[num] = {next_row, next_col};

    if (grid[next_row][next_col] > 0) {
        int removed_num = min(grid[next_row][next_col], num);
        int remained_num = max(grid[next_row][next_col], num);
        
        removed[removed_num] = true;
        weight[remained_num] += weight[removed_num];
        grid[next_row][next_col] = remained_num;
    }
    else {
        grid[next_row][next_col] = num;
    }
}

void simulate() {
    clearGrid();

    for (int i = 1; i <= m; i++) {
        if (removed[i])
            continue;
        
        move(i);
    }
}

int main() {
    cin >> n >> m >> t;
    for (int i = 1; i <= m; i++) {
        int r, c, w;
        char d;
        cin >> r >> c >> d >> w;
        position[i] = {r, c};
        direction[i] = d;
        weight[i] = w;
    }

    while(t--) {
        simulate();
    }

    int remain_cnt = 0;
    int max_weight = 0;
    for (int i = 1; i <= m; i++) {
        if (removed[i])
            continue;
        
        remain_cnt++;
        max_weight = max(max_weight, weight[i]);
    }

    cout << remain_cnt << " " << max_weight;

    return 0;
}