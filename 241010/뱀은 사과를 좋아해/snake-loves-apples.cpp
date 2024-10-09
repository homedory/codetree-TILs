#include <iostream>
#include <deque>
using namespace std;

#define MAX_N 105

int N, M, K;
int elapseed_time = 0;
bool terminated = false;
int grid[MAX_N][MAX_N];
deque <pair<int,int>> snake_position;
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, 1, -1};

bool inRange(int row, int column) {
    return row > 0 && row <= N && column > 0 && column <= N;
}

void move(int dir, int dist) {
    for (int i = 0; i < dist; i++) {
        elapseed_time++;

        int next_head_row = snake_position.front().first + dr[dir];
        int next_head_column = snake_position.front().second + dc[dir];
        int tail_row = snake_position.back().first;
        int tial_column = snake_position.back().second;

        if (!inRange(next_head_row, next_head_column) || grid[next_head_row][next_head_column] == 1) {
            terminated = true;
            break;
        }

        if (grid[next_head_row][next_head_column] != 2) {
            snake_position.pop_back();
            grid[tail_row][tial_column] = 0;
        }
        
        snake_position.push_front(make_pair(next_head_row, next_head_column));
        grid[next_head_row][next_head_column] = 1;
    }
}

int main() {
    cin >> N >> M >> K;
    for (int i = 0; i < M; i++) {
        int x,y;
        cin >> x >> y;
        grid[x][y] = 2;
    }

    snake_position.push_front(make_pair(1,1));
    grid[1][1] = 1;

    for (int i = 0; i < K; i++) {
        char dir;
        int p;
        cin >> dir >> p;

        if (terminated)
            continue;
        
        switch(dir) {
            case 'U':
                move(0, p);
                break;
            case 'D':
                move(1, p);
                break;
            case 'R':
                move(2, p);
                break;
            case 'L':
                move(3, p);
                break;
        }
    }

    cout << elapseed_time;


    return 0;
}