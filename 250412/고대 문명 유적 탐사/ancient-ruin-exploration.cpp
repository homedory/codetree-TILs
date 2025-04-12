#include <iostream>
using namespace std;

#define MAX_M 505

int K, M;
int grid[5][5];
int temp[5][5];
int visited[5][5];
int num_on_wall[MAX_M];
int num_order = 0;

void init_temp() {
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            temp[i][j] = grid[i][j];
            visited[i][j] = 0;
        }
    }
}

void copy_temp() {
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            grid[i][j] = temp[i][j];
        }
    }
}

void rotate_90(int row, int col) {
    for (int i = 0; i < 3; ++i) {        
        for (int j = 0; j < 3; ++j) {            
            temp[row + i][col + j] = grid[row + 2 - j][col + i];
        }
    }
}

void rotate_180(int row, int col) {
    for (int i = 0; i < 3; ++i) {        
        for (int j = 0; j < 3; ++j) {            
            temp[row + i][col + j] = grid[row + 2 - i][col + 2 - j];
        }
    }
}

void rotate_270(int row, int col) {
    for (int i = 0; i < 3; ++i) {        
        for (int j = 0; j < 3; ++j) {            
            temp[row + i][col + j] = grid[row + 2 - j][col + 2 - i];
        }
    }
}

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

int adjacent_cnt = 0;

void dfs(int row, int col, int num) {
    ++adjacent_cnt;
    visited[row][col] = 1;

    for (int dir = 0; dir < 4; ++dir) {
        int nr = row + dr[dir];
        int nc = col + dc[dir];

        if (nr < 0 || nr > 4 || nc < 0 || nc > 4)
            continue;
        
        if (visited[nr][nc] || temp[nr][nc] != num)
            continue;
        
        dfs(nr, nc, num);
    }
}

int getCount() {
    int cnt = 0;

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (visited[i][j])
                continue;
            
            adjacent_cnt = 0;
            dfs(i, j, temp[i][j]);

            if (adjacent_cnt >= 3)
                cnt += adjacent_cnt;       
        }
    }

    return cnt;
}

void erase_dfs(int row, int col, int num) {
    temp[row][col] = 0;

    for (int dir = 0; dir < 4; ++dir) {
        int nr = row + dr[dir];
        int nc = col + dc[dir];

        if (nr < 0 || nr > 4 || nc < 0 || nc > 4)
            continue;
        
        if (temp[nr][nc] != num)
            continue;
        
        erase_dfs(nr, nc, num);
    }
}

void erase_relics() {
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (visited[i][j])
                continue;

            adjacent_cnt = 0;
            dfs(i, j , temp[i][j]);

            if (adjacent_cnt >= 3)
                erase_dfs(i, j , temp[i][j]);

        }
    }
}

void fill_blank() {
    for (int c = 0; c < 5; ++c) {
        for (int r = 4; r >= 0; --r) {
            if (temp[r][c] > 0)
                continue;
            
            temp[r][c] = num_on_wall[num_order++];
        }
    }
}

int main() {
    cin >> K >> M;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            cin >> grid[i][j];
        }
    }
    for (int i = 0; i < M; ++i) {
        cin >> num_on_wall[i];
    }

    while(K--) {
        int total_value = 0;
        int max_cnt = 0;
        int max_rotation;
        int max_row;
        int max_col;

        for (int col = 0; col < 3; ++col) {
            for (int row = 0; row < 3; ++row) {
                init_temp();
                rotate_90(row, col);
                int count = getCount();

                if (max_cnt >= count)
                    continue;


                max_cnt = count;
                max_rotation = 1;
                max_row = row;
                max_col = col;
            }
        }


        for (int col = 0; col < 3; ++col) {
            for (int row = 0; row < 3; ++row) {
                init_temp();
                rotate_180(row, col);
                int count = getCount();

                if (max_cnt >= count)
                    continue;


                max_cnt = count;
                max_rotation = 2;
                max_row = row;
                max_col = col;
            }
        }

        for (int col = 0; col < 3; ++col) {
            for (int row = 0; row < 3; ++row) {
                init_temp();
                rotate_270(row, col);
                int count = getCount();

                if (max_cnt >= count)
                    continue;


                max_cnt = count;
                max_rotation = 3;
                max_row = row;
                max_col = col;
            }
        }


        if (max_cnt == 0)
            break;

        total_value += max_cnt;

        init_temp();
        if (max_rotation == 1) {
            rotate_90(max_row, max_col);
        }
        else if (max_rotation == 2) {
            rotate_180(max_row, max_col);
        }
        else {
            rotate_270(max_row, max_col);
        }
        
        erase_relics();
        fill_blank();
        copy_temp();


        while(1) {
            init_temp();
            int count = getCount();

            if (count == 0)
                break;

            total_value += count;

            init_temp();
            erase_relics();
            fill_blank();
            copy_temp();
            
        }
        
        cout << total_value << " ";
    }
    return 0;
}