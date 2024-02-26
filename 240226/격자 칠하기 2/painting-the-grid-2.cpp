#include <iostream>
using namespace std;

int N, cnt;
int arr[105][105], visit[105][105];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0 , 0 ,-1, 1};

void init() {
    cnt = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            visit[i][j] = 0;
        }
    }
}

void dfs(int x, int y, int d) {
    cnt++;
    visit[x][y] = 1;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < N && nx >= 0 && ny < N && ny >= 0 && visit[nx][ny] == 0) {
            if (abs(arr[nx][ny] - arr[x][y]) <= d) {
                dfs(nx, ny, d);
            }
        }
    }
}

bool IsPossible(int d) {
    init();

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (visit[i][j] == 0) {
                cnt = 0;
                dfs(i, j, d);

                if (cnt >= (N * N + 1) / 2)
                    return true;
            }
        }
    }

    return false;
}

int main() {
    

    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    int l = 0, r = 1000000;
    int ans = 1000000;

    while(l <= r) {
        int mid = (l + r) / 2;

        if (IsPossible(mid)) {
            r = mid - 1;
            ans = min(ans, mid);
        }
        else {
            l = mid + 1;
        }
    }

    cout << ans;


    return 0;
}