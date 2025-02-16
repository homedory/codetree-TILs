#include <iostream>

using namespace std;

int n;
int coin[1001];
int dp[1005][4];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> coin[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= min(i, 3); j++) {
            if (i >= 2)
                dp[i][j] = max(dp[i-2][j] + coin[i], dp[i][j]);
            
            if (j >= 1)
                dp[i][j] = max(dp[i-1][j-1] + coin[i], dp[i][j]);

        }
    }

    int ans = 0;
    for (int i = 0; i <= 3; i++)
        ans = max(ans, dp[n][i]);

    cout << ans;

    return 0;
}
