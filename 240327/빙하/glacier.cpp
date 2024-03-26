#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define MAX_N 205

int reached_time[MAX_N][MAX_N];
int board[MAX_N][MAX_N];
int N, M;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0 ,-1, 1};
queue <pair<int,int>> q;

bool inRange(int x, int y) {
    return x > 0 && x <= N && y > 0 && y <= M;
}

void findStartArea(int x, int y) {
    queue <pair<int,int>> start_q;

    reached_time[x][y] = 0;
    start_q.push(make_pair(x, y));
    while(!start_q.empty()) {
        auto [curr_x, curr_y] = start_q.front();
        start_q.pop();

        q.push(make_pair(curr_x, curr_y));

        for (int dir = 0; dir < 4; dir++) {
            int next_x = curr_x + dx[dir];
            int next_y = curr_y + dy[dir];

            if (inRange(next_x, next_y) && board[next_x][next_y] == 0 && reached_time[next_x][next_y] == -1) {
                reached_time[next_x][next_y] = 0;
                start_q.push(make_pair(next_x, next_y));
            }
        }
    }
}

void init() {
    for (int i = 1; i <= N; i++) {
        fill(reached_time[i], reached_time[i] + M, -1);
    }

    queue <pair<int, int>> init_q;

    for (int i = 1; i <= M; i++) {
        if (board[1][i] == 0 && reached_time[1][i] == -1) {
            findStartArea(1, i);
        }

        if (board[N][i] == 0 && reached_time[N][i] == -1) {
            findStartArea(N, i);
        }
    }

    for (int i = 2; i < N; i++) {
        if (board[i][1] == 0 && reached_time[i][1] == -1) {
            findStartArea(i, 1);
        }
        if (board[i][M] == 0 && reached_time[i][M] == -1) {
            findStartArea(i, M);
        }
    }
}

void addNewArea(int x, int y, int t) {
    queue <pair<int,int>> new_area_q;
    reached_time[x][y] = t;
    new_area_q.push(make_pair(x, y));

    while(!new_area_q.empty()) {
        auto [curr_x, curr_y] = new_area_q.front();
        new_area_q.pop();

        q.push(make_pair(curr_x, curr_y));

        for (int dir = 0; dir < 4; dir++) {
            int next_x = curr_x + dx[dir];
            int next_y = curr_y + dy[dir];

            if (board[next_x][next_y] == 1 || reached_time[next_x][next_y] >= 0)
                continue;
            
            reached_time[next_x][next_y] = t;
            new_area_q.push(make_pair(next_x, next_y));
        }
    }
}

void checkNewArea(int x, int y) {
    for (int dir = 0; dir < 4; dir++) {
        int next_x = x + dx[dir];
        int next_y = y + dy[dir];

        if (!inRange(next_x, next_y) || board[next_x][next_y] == 1 || reached_time[next_x][next_y] >= 0)
            continue;
        
        addNewArea(next_x, next_y, reached_time[x][y]);
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

    int curr_time = 0;

    while(!q.empty()) {
        auto [curr_x, curr_y] = q.front();
        q.pop();

        curr_time = reached_time[curr_x][curr_y];

        for (int dir = 0; dir < 4; dir++) {
            int next_x = curr_x + dx[dir];
            int next_y = curr_y + dy[dir];

            if (!inRange(next_x, next_y) || board[next_x][next_y] == 0 || reached_time[next_x][next_y] >= 0)
                continue;
            
            reached_time[next_x][next_y] = curr_time + 1;
            q.push(make_pair(next_x, next_y));
            checkNewArea(next_x, next_y);
        }
    }

    int glac_size = 0;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (reached_time[i][j] == curr_time && board[i][j] == 1)
                glac_size++;
        }
    }

    cout << curr_time << " " << glac_size;

    
    return 0;
}