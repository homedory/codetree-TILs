#include <iostream>
using namespace std;

#define MAX_N 15

int N, M, C;
int board[MAX_N][MAX_N];
int max_value_at_point[MAX_N][MAX_N];
int max_value;

void findMaxValue(int x, int y, int curr_cnt, int curr_weight, int curr_value) {
    if (curr_cnt == M) {
        if (curr_weight > C) {
            return;
        }
        max_value = max(max_value, curr_value);
        return;
    }

    if (y + curr_cnt > N)
        return;
    
    int weight = board[x][y + curr_cnt];
    int value = weight * weight;

    findMaxValue(x, y, curr_cnt + 1, curr_weight + weight, curr_value + value);
    findMaxValue(x, y, curr_cnt + 1, curr_weight, curr_value);
}

bool isPossible(int x1, int y1, int x2, int y2) {
    if (x1 != x2)
        return true;
    
    if (y2 + M <= y1 || y1 + M <= y2)
        return true;

    return false;
}

int main() {
    cin >> N >> M >> C;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            max_value = 0;
            findMaxValue(i,j, 0, 0, 0);
            max_value_at_point[i][j] = max_value;
        }
    }

    int ans = 0;

    for (int x1 = 1; x1 <= N; x1++) {
        for (int y1 = 1; y1 <= N; y1++) {
            for (int x2 = 1; x2 <= N; x2++) {
                for (int y2 = 1; y2 <= N; y2++) {
                    if (!isPossible(x1, y1, x2, y2))
                        continue;
                    ans = max(ans, max_value_at_point[x1][y1] + max_value_at_point[x2][y2]);

                }
            }
        }
    }

    cout << ans;

    return 0;
}