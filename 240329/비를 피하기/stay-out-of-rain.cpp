#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

#define MAX_N 105

int N, H, M;
int board[MAX_N][MAX_N];
int dist[MAX_N][MAX_N];
vector <pair<int,int>> shelter;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

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
    
    if (board[x][y] == 1 || dist[x][y] >= 0)
        return false;
    
    return true;
}

void findShortestDist() {
    init();

    queue <pair<int,int>> q;

    for (int i = 0; i < M; i++) {
        auto [x_point, y_point] = shelter[i];

        q.push(make_pair(x_point, y_point));
        dist[x_point][y_point] = 0;
    }

    while(!q.empty()) {
        auto[curr_x, curr_y] = q.front();
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
    cin >> N >> H >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
            if (board[i][j] == 3)
                shelter.push_back(make_pair(i, j));
        }
    }

    findShortestDist();

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == 2)
                cout << dist[i][j] << " ";
            else
                cout << 0 << " ";
        }
        cout << "\n";
    }

    return 0;
}