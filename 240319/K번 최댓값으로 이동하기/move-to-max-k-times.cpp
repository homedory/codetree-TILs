#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

#define MAX_N 105

int board[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];
int n, k;

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


bool canGo(int x, int y, int start_number) {
    return inRange(x, y) && !visited[x][y] && board[x][y] < start_number;
}


pair<int,int> findNextPoint(int start_x, int start_y) {
    initVisited();

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    int start_number = board[start_x][start_y];
    int possible_next_x = n + 1, possible_next_y = n + 1;
    int max_num = 0;

    queue<pair<int,int>> point_queue;

    visited[start_x][start_y] = true;

    for (int dir = 0; dir < 4; dir++) {
        int next_x = start_x + dx[dir];
        int next_y = start_y + dy[dir];

        if (!canGo(next_x, next_y, start_number))
            continue;
        
        visited[next_x][next_y] = true;
        point_queue.push(make_pair(next_x, next_y));
    }

    while(!point_queue.empty()) {
        auto [current_x, current_y] = point_queue.front();
        point_queue.pop();

        int current_num = board[current_x][current_y];

        auto a = make_tuple(max_num, -possible_next_x, -possible_next_y);
        auto b = make_tuple(current_num, -current_x, -current_y);
        
        if (a < b) {
            max_num = current_num;
            possible_next_x = current_x;
            possible_next_y = current_y;
        }


        for (int dir = 0; dir < 4; dir++) {
            int next_x = current_x + dx[dir];
            int next_y = current_y + dy[dir];

            if (!canGo(next_x, next_y, start_number))
                continue;
            
            visited[next_x][next_y] = true;
            point_queue.push(make_pair(next_x, next_y));
        }

    }

    return make_pair(possible_next_x, possible_next_y);

}
int main() {
    int r, c;

    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> board[i][j];
        }
    }
    cin >> r >> c;

    for (int i = 0; i < k; i++) {
        auto [next_r, next_c] = findNextPoint(r, c);
        if (next_r == n + 1 && next_c == n + 1) {
            break;
        }
        r = next_r;
        c = next_c;
    }

    cout << r << " " << c;

    return 0;
}