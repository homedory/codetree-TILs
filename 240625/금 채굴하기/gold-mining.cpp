#include <iostream>
using namespace std;

int n, m;
int grid[25][25];


int findMax(int x, int y) {
    int max_cnt = 0;

    for (int k = 0; k <= n; k++) {
        int gold_count = 0;

        for (int i = -k; i <= k; i++) {
            int nx = x + i;
            if (nx < 0 || nx > n)
                continue;
            
            for (int j = -(k - abs(i)); j <= (k - abs(i)); j++) {
                int ny = y + j;
                if (ny < 0 || ny > n)
                    continue;
                
                if (grid[nx][ny] == 1)
                    gold_count++;
            }
        }

        if (k*k + (k+1)*(k+1) > m * gold_count)
            continue;
        
        max_cnt = max(max_cnt, gold_count);

    }
    
    return max_cnt;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    int ans = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int cnt = findMax(i, j);
            ans = max(ans, cnt);
        }
    }

    cout << ans;

    return 0;
}