#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define MAX_N 105

int dist[MAX_N][MAX_N];
int board[MAX_N][MAX_N];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int N, M;

void init() {
    for (int i = 1; i <= N; i++) {
        fill(dist[i] + 1, dist[i] + M + 1, -1);
    }
}

bool inRange(int x, int y) {
    return x > 0 && x <= N && y > 0 && y <= M;
}

bool canGo(int x, int y) {
    return inRange(x, y) && board[x][y] && dist[x][y] < 0;
}

void findShortesDist() {
    queue <pair<int,int>> q;

    dist[1][1] = 0;
    q.push(make_pair(1, 1));

    while(!q.empty()) {
        auto [curr_x, curr_y] = q.front();
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int next_x = curr_x + dx[dir];
            int next_y = curr_y + dy[dir];

            if (!canGo(next_x, next_y))
                continue;
            
            dist[next_x][next_y] = dist[curr_x][curr_y] + 1;
            q.push(make_pair(next_x, next_y));
        }
    }
}

int main() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> board[i][j];
        }
    }

    init();

    findShortesDist();

    cout << dist[N][M];

    return 0;
}