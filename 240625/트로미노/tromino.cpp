#include <iostream>
using namespace std;

int n, m;
int num[205][205];

int block1(int x, int y) {
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    int max_sum = 0;
    for (int i = 0; i < 4; i++) {
        int j = (i + 1) % 4;

        int nx_1 = x + dx[i];
        int ny_1 = y + dy[i];
        int nx_2 = x + dx[j];
        int ny_2 = y + dy[j];
        
        if (nx_1 < 0 || nx_1 > n || nx_2 < 0 || nx_2 > n)
            continue;

        if (ny_1 < 0 || ny_1 > m || ny_2 < 0 || ny_2 > m)
            continue;
        
        max_sum = max(max_sum, num[x][y] + num[nx_1][ny_1] + num[nx_2][ny_2]);

    }

    return max_sum;
}

int block2(int x, int y) {
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    int max_sum = 0;
    for (int i = 0; i < 2; i++) {
        int j = 2*i + 1;

        int nx_1 = x + dx[2*i];
        int ny_1 = y + dy[2*i];
        int nx_2 = x + dx[j];
        int ny_2 = y + dy[j];
        
        if (nx_1 < 0 || nx_1 > n || nx_2 < 0 || nx_2 > n)
            continue;

        if (ny_1 < 0 || ny_1 > m || ny_2 < 0 || ny_2 > m)
            continue;
        
        max_sum = max(max_sum, num[x][y] + num[nx_1][ny_1] + num[nx_2][ny_2]);

    }

    return max_sum;
}


int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> num[i][j];
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ans = max(ans, block1(i, j));
            ans = max(ans, block2(i, j));
        }
    }

    cout << ans;

    return 0;
}