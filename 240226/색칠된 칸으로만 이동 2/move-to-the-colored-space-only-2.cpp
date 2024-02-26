#include <iostream>
using namespace std;

#define MAX_N 100

int M, N, sx, sy, colored_cnt = 0;
int num[MAX_N][MAX_N], color[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void init() {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            visited[i][j] = false;
        }
    }
}

int dfs(int x, int y, int d) {
    int cnt = 0;

    if (color[x][y] == 1) 
        cnt++;
    
    visited[x][y] = true;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < M && nx >= 0 && ny < N && ny >= 0 && !visited[nx][ny]) {
            if (abs(num[x][y] - num[nx][ny]) <= d) {
                cnt += dfs(nx, ny, d);
            }
        }
    }

    return cnt;
}

bool IsPossible(int d) {
    init();
    
    return dfs(sx, sy, d) == colored_cnt;
}

int main() {
    cin >> M >> N;

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> num[i][j];
        }
    }

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> color[i][j];
            if (color[i][j] == 1) {
                colored_cnt++;
                sx = i;
                sy = j;
            }
                
        }
    }


    int l = 0, r = 1000000000;
    int ans;

    while(l <= r) {
        int mid = (l + r) / 2;

        if (IsPossible(mid)) {
            r = mid - 1;
            ans = mid;
        }
        else {
            l = mid + 1;
        }
    }


    cout << ans;

    return 0;
}