#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define MAX_N 105

int dist[MAX_N][MAX_N];
int board[MAX_N][MAX_N];
int ans[MAX_N][MAX_N];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0 ,-1, 1};
int N, M, H;

void init() {
    for (int i = 0; i < N; i++) {
        fill(dist[i], dist[i] + N, -1);
    }
}

bool inRange(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < N;
}

bool canGo(int x, int y) {
    if (!inRange(x, y))
        return false;
    
    if (dist[x][y] >= 0 || board[x][y] == 1)
        return false;

    return true;
}

int findShortestDist(int start_x, int start_y) {
    init();

    int min_dist = -1;
    queue <pair<int,int>> q;

    dist[start_x][start_y] = 0;
    q.push(make_pair(start_x, start_y));

    while(!q.empty()) {
        auto[curr_x, curr_y] = q.front();
        q.pop();

        if (board[curr_x][curr_y] == 3) {
            min_dist = dist[curr_x][curr_y];
            break;
        }

        for (int dir = 0; dir < 4; dir++) {
            int next_x = curr_x + dx[dir];
            int next_y = curr_y + dy[dir];

            if (!canGo(next_x, next_y))
                continue;
            
            dist[next_x][next_y] = dist[curr_x][curr_y] + 1;
            q.push(make_pair(next_x, next_y));
        }
    }

    return min_dist;
}

int main() {
    cin >> N >> M >> H;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == 2) {
                ans[i][j] = findShortestDist(i, j);
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}