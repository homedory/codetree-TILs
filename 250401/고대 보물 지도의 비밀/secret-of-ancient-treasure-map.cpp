#include <iostream>
using namespace std;

#define MAX_K 12
#define MAX_N 100005

int dp[MAX_N][MAX_K];
int num[MAX_N];

int main() {
    int N, K;

    cin >> N >> K;

    for (int i = 1; i <= N; ++i) {
        cin >> num[i];
    }

    for (int i = 1; i <= N; ++i) {
        if (num[i] < 0)
            dp[i][0] = 0;
        else
            dp[i][0] = dp[i-1][0] + num[i];
    }

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= K; ++j) {
            if (num[i] < 0) {
                dp[i][j] = dp[i-1][j-1] + num[i];
            }
            else {
                dp[i][j] = dp[i-1][j] + num[i];
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j <= K; ++j) {
            ans = max(ans, dp[i][j]);
        }
    }

    cout << ans;

    return 0;
}