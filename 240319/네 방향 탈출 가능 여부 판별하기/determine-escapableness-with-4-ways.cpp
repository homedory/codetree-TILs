#include <iostream>
#include <queue>
using namespace std;

#define MAX_N 105

int board[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];
int n, m;

bool inRange(int x, int y) {
    return x > 0 && x <= n && y > 0 && y <= m;
}

bool canGo(int x, int y) {
    if (!inRange(x, y))
        return false;
    
    if (visited[x][y] || board[x][y] == 0)
        return false;
    
    return true;
}

void bfs(int start_x, int start_y) {
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    queue <pair<int,int>> points_queue;

    visited[start_x][start_y] = true;
    points_queue.push(make_pair(start_x, start_y));

    while(!points_queue.empty()) {
        auto [current_x, current_y] = points_queue.front();
        points_queue.pop();

        for (int i = 0; i < 4; i++) {
            int next_x = current_x + dx[i];
            int next_y = current_y + dy[i];

            if (!canGo(next_x, next_y))
                continue;
        
            visited[next_x][next_y] = true;
            points_queue.push(make_pair(next_x, next_y));
        }
    }
}

int main() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> board[i][j];
        }
    }

    bfs(1, 1);

    if (visited[n][m]) 
        cout << 1;
    else
        cout << 0;


    return 0;
}