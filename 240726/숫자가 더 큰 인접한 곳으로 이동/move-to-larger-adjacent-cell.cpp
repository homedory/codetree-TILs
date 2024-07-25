#include <iostream>
using namespace std;

int n;
int curr_x, curr_y;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int grid[105][105];

bool inRange(int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= n;
}

bool move() {
    bool moved = false;

    for (int dir = 0; dir < 4; dir++) {
        int next_x = curr_x + dx[dir];
        int next_y = curr_y + dy[dir];

        if (inRange(next_x, next_y) && grid[curr_x][curr_y] < grid[next_x][next_y]) {
            curr_x = next_x;
            curr_y = next_y;
            moved = true;
            break;
        }
    }

    return moved;
}

int main() {
    cin >> n >> curr_x >> curr_y;  
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> grid[i][j];
        }
    }
    
    cout << grid[curr_x][curr_y] << " ";
    while(move()) {
        cout << grid[curr_x][curr_y] << " ";
    }
    
    return 0;
}