#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define MAX_N 105

int board[MAX_N][MAX_N];
int reached_time[MAX_N][MAX_N];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int N, K;
queue <pair<int,int>> q;

void init() {
    for (int i = 0; i < N; i++) 
        fill(reached_time[i], reached_time[i] + N, -2);
}

bool inRange(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < N;
}

bool canGo(int x, int y) {
    if (!inRange(x, y))
        return false;
    
    if (board[x][y] != 1 || reached_time[x][y] >= 0)
        return false;
    
    return true;
}

void simulate() {
    while(!q.empty()) {
        auto [curr_x, curr_y] = q.front();
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int next_x = curr_x + dx[dir];
            int next_y = curr_y + dy[dir];

            if (!canGo(next_x, next_y))
                continue;
            
            reached_time[next_x][next_y] = reached_time[curr_x][curr_y] + 1;
            q.push(make_pair(next_x, next_y));
        }
    }
}

int main() {
    cin >> N >> K;

    init();

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
            
            if (board[i][j] == 2) {
                q.push(make_pair(i, j));
                reached_time[i][j] = 0;
            }
            else if (board[i][j] == 0) {
                reached_time[i][j] = -1;
            }            
        }
    }

    simulate();

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << reached_time[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}