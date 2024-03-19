#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define MAX_N 105

int board[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];
int n, k, cnt = 0;

bool inRange(int x, int y) {
    return x > 0 && x <= n && y > 0 && y <= n;
}

bool canGo(int x, int y) {
    return inRange(x, y) && !visited[x][y] && board[x][y] == 0;
}

int getMovableBlockCnt(int start_x, int start_y) {
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    int block_cnt = 0;

    if (visited[start_x][start_y])
        return 0;
    
    visited[start_x][start_y] = true;

    queue<pair<int,int>> point_queue;
    point_queue.push(make_pair(start_x, start_y));

    while(!point_queue.empty()) {
        auto [current_x, current_y] = point_queue.front();
        point_queue.pop();

        block_cnt++;

        for (int dir = 0; dir < 4; dir++) {
            int next_x = current_x + dx[dir];
            int next_y = current_y + dy[dir];

            if (!canGo(next_x, next_y))
             continue;
            
            visited[next_x][next_y] = true;
            point_queue.push(make_pair(next_x, next_y));
        }
    }

    return block_cnt;
}

int main() {
    vector <pair<int,int>> start_point;
    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < k; i++) {
        int r, c;
        cin >> r >> c;
        start_point.push_back(make_pair(r, c));
    }

    int total_cnt = 0;

    for (int i = 0; i < start_point.size(); i++) {
        auto [start_x, start_y] = start_point[i];

        total_cnt += getMovableBlockCnt(start_x, start_y);
    }

    cout << total_cnt;

    return 0;
}