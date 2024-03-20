#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX_N 105

int n, m, k;
int board[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];
vector <pair<int,int>> start_point, rock_point;
int total_rock_cnt = 0, max_cnt = 0;

void initVisited() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            visited[i][j] = false;
        }
    }
}

bool inRange(int x, int y) {
    return x > 0 && x <= n && y > 0 && y <= n;
}

bool canGo(int x, int y) {
    return inRange(x, y) && !visited[x][y] && board[x][y] == 0;
}

int countMovableBlock() {
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    initVisited();

    int cnt = 0;

    for (auto start : start_point) {
        int start_x = start.first, start_y = start.second;

        if (visited[start_x][start_y])
            continue;

        queue <pair<int,int>> point_queue;
        
        visited[start_x][start_y] = true;
        point_queue.push(make_pair(start_x, start_y));
    
        while(!point_queue.empty()) {
            auto [current_x, current_y] = point_queue.front();
            point_queue.pop();
            cnt++;

            for (int dir = 0; dir < 4; dir++) {
                int next_x = current_x + dx[dir];
                int next_y = current_y + dy[dir];

                if (!canGo(next_x, next_y))
                    continue;
                
                visited[next_x][next_y] = true;
                point_queue.push(make_pair(next_x, next_y));
            }
        }
    }

    return cnt;
}

void removeRock(int index, int depth) {
    auto [current_x, current_y] = rock_point[index];
    board[current_x][current_y] = 0;

    if (depth == m) {
        int cnt = countMovableBlock();
        max_cnt = max(max_cnt, cnt);

        board[current_x][current_y] = 1;
        return;
    }

    for (int i = index + 1; i < total_rock_cnt; i++) {
        removeRock(i, depth + 1);
    }

    board[current_x][current_y] = 1;
    
    return;
}

int main() {
    cin >> n >> k >> m;

    for (int i = 1; i <= n; i++) { 
        for (int j = 1; j <= n; j++) {
            cin >> board[i][j];
            if (board[i][j] == 1) {
                rock_point.push_back(make_pair(i, j));
                total_rock_cnt++;
            }
        }
    }

    for (int i = 0; i < k; i++) {
        int r, c;
        cin >> r >> c;
        start_point.push_back(make_pair(r, c));
    }

    max_cnt = countMovableBlock();

    for (int i = 0; i < total_rock_cnt; i++) {
        removeRock(i, 1);
    }

    cout << max_cnt;

    return 0;
}