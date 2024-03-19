#include <iostream>
using namespace std;

#define MAX_N 55

int N, M;
int house[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];

bool canGo(int x, int y, int height) {
    if (x > 0 && x <= N && y > 0 && y <= M && house[x][y] > height)
        return true;
    
    return false;
}

void dfs(int x, int y, int height) {
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (canGo(nx, ny, height) && !visited[nx][ny]) {
            visited[nx][ny] = true;
            dfs(nx, ny, height);
        }
    }
}

void initialize() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            visited[i][j] = false;
        }
    }
}

int main() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> house[i][j];
        }
    }

    int max_cnt = 0, max_k = 1;
    for (int k = 1; k <= 100; k++) {
        int cnt = 0;

        initialize();

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                if (visited[i][j] || house[i][j] <= k)
                    continue;
                
                cnt++;
                dfs(i, j, k);
            }
        }

        if (cnt > max_cnt) {
            max_cnt = cnt;
            max_k = k;
        }
    }

    cout << max_k << " " << max_cnt;
    return 0;
}