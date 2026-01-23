#include <iostream>
using namespace std;

#define MAX_N 1000
#define DIV 1000000007

int dp[MAX_N + 1][10];

int main() {
    int N;
    cin >> N;

    for (int i = 1; i <= 9; i++) {
        dp[1][i] = 1;
    }

    for (int i = 2; i <= N; i++) {
        dp[i][0] += dp[i-1][1];
        dp[i][0] %= DIV;
        dp[i][9] += dp[i-1][8];
        dp[i][9] %= DIV;

        for (int j = 1; j <= 8; j++) {
            dp[i][j] += dp[i-1][j+1];
            dp[i][j] += dp[i-1][j-1];
            dp[i][j] %= DIV;
        }
    }

    int ans = 0;
    for (int i = 0; i <= 9; i++) {
        ans += dp[N][i];
    }

    cout << ans;

    return 0;
}