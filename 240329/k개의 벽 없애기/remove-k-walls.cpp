#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

#define MAX_N 105

int board[MAX_N][MAX_N];
int dist[MAX_N][MAX_N];
vector <pair<int,int>> wall;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int N, K, r1, c1, r2, c2;
int min_dist;

void init() {
    for (int i = 1; i <= N; i++) {
        fill(dist[i] + 1, dist[i] + N + 1, -1);
    }
}

bool inRange(int x, int y) {
    return x > 0 && x <= N && y > 0 && y <= N;
}

bool canGo(int x, int y) {
    if (!inRange(x, y))
        return false;
    
    if (board[x][y] == 1 || dist[x][y] >= 0)
        return false;
    
    return true;
}

int findShortestPath(int start_x, int start_y, int end_x, int end_y) {
    init();

    queue <pair<int,int>> q;

    dist[start_x][start_y] = 0;
    q.push(make_pair(start_x, start_y));

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

    return dist[end_x][end_y];
}

void removeWall(int curr_idx, int curr_cnt) {
    if (curr_cnt == K) {
        int shortest_dist = findShortestPath(r1, c1, r2, c2);
        if (shortest_dist != -1) {
            min_dist = min(min_dist, shortest_dist);
        }
        return;
    }

    if (curr_idx == wall.size())
        return;
    
    auto [curr_x, curr_y] = wall[curr_idx];

    board[curr_x][curr_y] = 0;
    removeWall(curr_idx + 1, curr_cnt + 1);

    board[curr_x][curr_y] = 1;
    removeWall(curr_idx + 1, curr_cnt);
}

int main() {
    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> board[i][j];
            if (board[i][j] == 1)
                wall.push_back(make_pair(i, j));
        }
    }
    cin >> r1 >> c1 >> r2 >> c2;

    min_dist = N * N;

    removeWall(0, 0);

    if (min_dist == N * N) {
        cout << -1;
    }
    else {
        cout << min_dist;
    }

    return 0;
}