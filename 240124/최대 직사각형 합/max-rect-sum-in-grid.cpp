#include <iostream>
using namespace std;
#define MAX_N 305

int arr[MAX_N][MAX_N], prefix_sum[MAX_N][MAX_N];

int main() {
    int n, ans = -1000;

    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            prefix_sum[i][j] = prefix_sum[i-1][j] + prefix_sum[i][j-1] - prefix_sum[i-1][j-1] + arr[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            int dp[MAX_N];
            dp[0] = 0;
            int max_sum = 0;
            for (int k = 1; k <= n; k++) {
                int value = prefix_sum[j][k] - prefix_sum[i-1][k] - prefix_sum[j][k-1] + prefix_sum[i-1][k-1]; 
                dp[k] = max(dp[k-1] + value, value);
                max_sum = max(max_sum, dp[k]);
            }

            ans = max(ans, max_sum);
        }
    }

    cout << ans;
    return 0;
}