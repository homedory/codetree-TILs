#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define MAX_N 105
#define DIR_CNT 8

int N;
int move_cnt[MAX_N][MAX_N];
int dx[8] = {-1, -1, 1, 1, -2, -2, 2, 2};
int dy[8] = {-2, 2, -2, 2, 1, -1, 1, -1};

void init() {
    for (int i = 1; i <= N; i++) {
        fill(move_cnt[i] + 1, move_cnt[i] + N + 1, -1);
    }
}

bool inRange(int x, int y) {
    return x > 0 && x <= N && y > 0 && y <= N;
}

bool canGo(int x, int y) {
    return inRange(x, y) && move_cnt[x][y] < 0;
}

void findMoveCnt(int start_x, int start_y) {
    init();

    queue <pair<int,int>> q;

    move_cnt[start_x][start_y] = 0;
    q.push(make_pair(start_x, start_y));

    while(!q.empty()) {
        auto [curr_x, curr_y] = q.front();
        q.pop();

        for (int dir = 0; dir < DIR_CNT; dir++) {
            int next_x = curr_x + dx[dir];
            int next_y = curr_y + dy[dir];

            if (!canGo(next_x, next_y))
                continue;
            
            move_cnt[next_x][next_y] = move_cnt[curr_x][curr_y] + 1;
            q.push(make_pair(next_x, next_y));
        }
    }
}

int main() {
    cin >> N;
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;

    findMoveCnt(r1, c1);

    cout << move_cnt[r2][c2];
    
    return 0;
}