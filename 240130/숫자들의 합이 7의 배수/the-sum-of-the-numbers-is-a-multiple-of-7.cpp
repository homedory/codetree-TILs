#include <iostream>
using namespace std;

#define MAX_N 50005

int dp[MAX_N][7];
int arr[MAX_N];

int main() {
    int N;

    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    for (int i = 1; i <= N; i++) {
        int k = arr[i] % 7;

        dp[i][k] = dp[i-1][0] + 1;

        for (int j = 1; j < 7; j++) {
            if (dp[i-1][j] == 0)
                continue;

            k = (j + arr[i]) % 7;
            dp[i][k] = dp[i-1][j] + 1;
        }
    }

    int ans = 0;
    for (int i = 1; i <= N; i++) {
        ans = max(ans, dp[i][0]);
    }

    cout << ans;

    
    return 0;
}