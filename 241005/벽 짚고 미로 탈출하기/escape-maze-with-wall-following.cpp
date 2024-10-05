#include <iostream>
using namespace std;

#define MAX_N 205

int N, cur_x, cur_y;
char grid[MAX_N][MAX_N];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int turnLeft(int dir) {
    return ((dir == 0) ? 3: dir-1);
}

int turnRigiht(int dir) {
    return (dir + 1) % 4;
}

bool canMove(int dir) {
    int next_x = cur_x + dx[dir];
    int next_y = cur_y + dy[dir];

    if (next_x < 0 || next_x >= N || next_y < 0 || next_y >= N)
        return true;
    else if (grid[next_x][next_y] == '.')
        return true;
    else
         return false;
}

void move(int dir) {
    cur_x += dx[dir];
    cur_y += dy[dir];
}

bool hasEnded() {
    if (cur_x < 0 || cur_x >= N || cur_y < 0 || cur_y >= N)
        return true;
    
    return false;
}

bool rightWallExists(int dir) {
    int right_dir = turnRigiht(dir);
    int right_x = cur_x + dx[right_dir];
    int right_y = cur_y + dy[right_dir];

    return grid[right_x][right_y] == '#';
}

int main() {
    cin >> N;
    cin >> cur_x >> cur_y;
    for (int i = 0; i < N; i++) {
        cin >> grid[i];
    }

    cur_x -= 1;
    cur_y -= 1;
    int total_time = 0;
    int dir = 0;
    int turn_left_cnt = 0;
    while(total_time < N*N && turn_left_cnt < 4) {
        if (canMove(dir)) {
            turn_left_cnt = 0;

            move(dir);
            total_time++;

            if (hasEnded())
                break;
            
            if (rightWallExists(dir))
                continue;
            
            dir = turnRigiht(dir);
            move(dir);
            total_time++;
        }
        else {
            dir = turnLeft(dir);
            turn_left_cnt++;
        }
    }

    if (total_time >= N*N || turn_left_cnt >= 4)
        cout << -1;
    else 
        cout << total_time;


    return 0;
}