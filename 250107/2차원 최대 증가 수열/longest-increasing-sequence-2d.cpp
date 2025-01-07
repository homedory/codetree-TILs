#include <iostream>

using namespace std;

int n, m;
int grid[50][50];
int dp[50][50];

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int x = 0; x <= i; x++) {
                for (int y = 0; y <= j; y++) {
                    if (x < i && y < j && grid[i][j] > grid[x][y]) 
                        dp[i][j] = max(dp[x][y] + 1, dp[i][j]);
            
                    else if (x == i || y == j) 
                        dp[i][j] = max(dp[x][y], dp[i][j]);
                    
                }
            }
        }
    }
    
    cout << dp[n-1][m-1] + 1;

    return 0;
}
