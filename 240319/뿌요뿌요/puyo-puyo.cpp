#include <iostream>
using namespace std;

#define MAX_N 105

const int POP_CRITERIA = 4;

int N;
int board[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];

bool range(int x, int y) {
    if (x > 0 && x <= N && y > 0 && y <= N) 
        return true;
    
    return false;
}

int getBlockSize(int x, int y) {
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    int sum = 1;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (range(nx, ny) && board[x][y] == board[nx][ny] && !visited[nx][ny]) {
            visited[nx][ny] = true;
            sum += getBlockSize(nx, ny);
        }
    }

    return sum;
}

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> board[i][j];
        }
    }

    int block_cnt = 0;
    int max_block_size = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (visited[i][j])
                continue;
            
            visited[i][j] = true;
            int block_size = getBlockSize(i, j);
            max_block_size = max(max_block_size, block_size);

            if (block_size < POP_CRITERIA)
                continue;
                
            block_cnt++;
        }
    }

    cout << block_cnt << " " << max_block_size;

    return 0;
}