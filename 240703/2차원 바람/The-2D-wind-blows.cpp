#include <iostream>
using namespace std;

int N, M, Q;
int building[105][105];
int tmp_grid[105][105];


void rotate(int r1, int c1, int r2, int c2) {
    int tmp1 = building[r1][c2];
    for (int i = c2; i > c1; i--) {
        building[r1][i] = building[r1][i-1];
    }
    
    int tmp2 = building[r2][c2];
    for (int i = r2; i > r1 + 1; i--) {
        building[i][c2] = building[i-1][c2];
    }
    building[r1+1][c2] = tmp1;

    tmp1 = building[r2][c1];
    for (int i = c1; i < c2 - 1; i++) {
        building[r2][i] = building[r2][i+1];
    }
    building[r2][c2-1] = tmp2;

    for (int i = r1; i < r2 - 1; i++) {
        building[i][c1] = building[i+1][c1];
    }
    building[r2-1][c1] = tmp1;   
}

void copy(int r1, int c1, int r2, int c2) {
    r1 = (r1 > 1) ? (r1-1) : r1;
    c1 = (c1 > 1) ? (c1-1) : c1;
    r2 = (r2 < N) ? (r2+1) : r2;
    c2 = (c2 < M) ? (c2+1) : c2;

    for (int i = r1; i <= r2; i++) {
        for (int j = c1; j <= c2; j++) {
            tmp_grid[i][j] = building[i][j];
        }
    }
}

int average(int x, int y) {
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    
    int sum = tmp_grid[x][y];
    int num_cnt = 1;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 1 || nx > N || ny < 1 || ny > M)
            continue;
        sum += tmp_grid[nx][ny];
        num_cnt++;
    }

    return sum / num_cnt;
}

void toAverage(int r1, int c1, int r2, int c2) {
    for (int i = r1; i <= r2; i++) {
        for (int j = c1; j <= c2; j++) {
            building[i][j] = average(i, j);
        }
    }
}

int main() {
    cin >> N >> M >> Q;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> building[i][j];
        }
    }

    while(Q--) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;

        rotate(r1, c1, r2, c2);
        copy(r1, c1, r2, c2);
        toAverage(r1, c1, r2, c2);
    }

    // answer
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cout << building[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}