#include <iostream>
#include <vector>
using namespace std;

#define MAX_N 25

int n;
int board[MAX_N][MAX_N];
bool checked[MAX_N][MAX_N];
vector <pair<int,int>> bomb_pos;
int bomb_cnt = 0, max_cnt = 0;
int dx[3][4] = {{-2, -1, 1, 2}, {-1, 1, 0 , 0}, {-1, -1, 1, 1}};
int dy[3][4] = {{0, 0, 0, 0}, { 0, 0 , -1, 1}, {-1, 1, -1, 1}};

bool inRange(int x, int y) {
    return x > 0 && x <= n && y > 0 && y <= n;
}

bool canExplode(int x, int y) {
    return inRange(x, y) && !checked[x][y] && board[x][y] == 0;
}

void chooseType(int curr_cnt, int explosion_cnt) {
    if (curr_cnt == bomb_cnt) {
        max_cnt = max(max_cnt, explosion_cnt);
        return;
    }

    auto [curr_x, curr_y] = bomb_pos[curr_cnt];
    
    for (int type = 0; type < 3; type++) {
        int cnt = 1;

        vector <pair<int,int>> checked_point;

        for (int dir = 0; dir < 4; dir++) {
            int nx = curr_x + dx[type][dir];
            int ny = curr_y + dy[type][dir];

            if (canExplode(nx, ny)) {
                checked[nx][ny] = true;
                cnt++;
                checked_point.push_back(make_pair(nx,ny));
            }
        }

        chooseType(curr_cnt + 1, explosion_cnt + cnt);

        for (auto point : checked_point) {
            checked[point.first][point.second] = false;
        }
        
    }
}

int main() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> board[i][j];
            if (board[i][j]) {
                bomb_pos.push_back(make_pair(i, j));
                bomb_cnt++;
            }
        }
    }

    chooseType(0, 0);

    cout << max_cnt;


    return 0;
}