#include <iostream>
#include <climits>
using namespace std;

int num[305][305];
int prefix_sum[305][305];
int n;

int getMax(int row1, int row2) {
    int dp[305];
    int max_val = INT_MIN;

    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        int sum = 0;
        
        sum = prefix_sum[row2][i] - prefix_sum[row1-1][i] - prefix_sum[row2][i-1] + prefix_sum[row1-1][i-1];
        dp[i] = max(dp[i-1], 0) + sum;
        max_val = max(max_val, dp[i]);
    }

    return max_val;
}

int main() {
    cin >> n;

    for (int i  = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> num[i][j];
            prefix_sum[i][j] = prefix_sum[i-1][j] + prefix_sum[i][j-1] - prefix_sum[i-1][j-1] + num[i][j];
        }
    }

    int ans = INT_MIN;

    for (int row1 = 1; row1 <= n; row1++) {
        for (int row2 = row1; row2 <= n; row2++) {
            ans = max(ans, getMax(row1, row2));
        }
    }

    cout << ans;

    return 0;
}