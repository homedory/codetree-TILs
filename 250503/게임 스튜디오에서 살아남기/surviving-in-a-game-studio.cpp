#include <iostream>
using namespace std;

#define MAX_T 4
#define MAX_B 4
#define MAX_N 1005
#define DIV 1000000007

int dp[MAX_T][MAX_B][MAX_N];

int main() {
    int N;

    cin >> N;

    dp[0][0][0] = 1;

    for (int n = 1; n <= N; n++) {
        // choose G
        for (int b = 0; b < 3; b++) {
            dp[0][0][n] += dp[0][b][n-1];
            dp[0][0][n] %= DIV;
            dp[1][0][n] += dp[1][b][n-1];
            dp[1][0][n] %= DIV;
            dp[2][0][n] += dp[2][b][n-1];
            dp[2][0][n] %= DIV;
        }

        // chose B
        for (int b = 1; b < 3; b++) {
            dp[0][b][n] += dp[0][b-1][n-1];
            dp[0][b][n] %= DIV;
            dp[1][b][n] += dp[1][b-1][n-1];
            dp[1][b][n] %= DIV;
            dp[2][b][n] += dp[2][b-1][n-1];
            dp[2][b][n] %= DIV;
        }

        // chose T
        for (int t = 1; t < 3; t++) {
            for (int b = 0; b < 3; b++) {
                dp[t][0][n] += dp[t-1][b][n-1];
                dp[t][0][n] %= DIV;
            }
        }
    }

    int ans = 0;

    for (int t = 0; t < 3; t++) {
        for (int b = 0; b < 3; b++) {
            ans = (ans + dp[t][b][N]) % DIV;
        }
    }
    
    cout << ans;
    
    return 0;
}