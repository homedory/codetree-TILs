#include <iostream>
using namespace std;

#define MAX_N 105
#define INT_MAX 105
int n;
int grid[MAX_N][MAX_N];
int dp[MAX_N][MAX_N][MAX_N];

void initialize() {
    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= n; j++) 
            for (int k = 1; k <= 100; k++) 
                dp[i][j][k] = INT_MAX;
    
    dp[1][1][grid[1][1]] = grid[1][1];

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= 100; j++) {
            if (dp[1][i-1][j] == INT_MAX)
                continue;
            dp[1][i][min(j, grid[1][i])] = max(dp[1][i-1][j], grid[1][i]);
        }
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= 100; j++) {
            if (dp[i-1][1][j] == INT_MAX)
                continue;
            dp[i][1][min(j, grid[i][1])] = max(dp[i-1][1][j], grid[i][1]);
        }
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> grid[i][j];
        }
    }

    initialize();

    for (int i = 2; i <= n; i++) {
        for (int j = 2; j <= n; j++) {
            for (int k = 1; k <= 100; k++) {
                if (min(dp[i][j-1][k], dp[i-1][j][k]) == INT_MAX)
                    continue;

                dp[i][j][min(k, grid[i][j])] = min(dp[i][j][min(k, grid[i][j])], 
                                                    max(min(dp[i][j-1][k], dp[i-1][j][k]), grid[i][j]));
            }
        }
    }

    int ans = INT_MAX;
    for (int i = 1; i <= 100; i++) {
        if (dp[n][n][i] == INT_MAX)
            continue;
        
        ans = min(ans, dp[n][n][i] - i);
    }

    cout << ans;

    return 0;
}