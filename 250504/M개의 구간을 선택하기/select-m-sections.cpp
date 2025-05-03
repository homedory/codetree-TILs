#include <iostream>
using namespace std;

#define MAX_N 505
#define MAX_M 255
#define MIN_VAL -2000000000
int dp[MAX_N][MAX_M];

int main() {
    int N, M;
    int num[MAX_N];
    
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        cin >> num[i];
    }

    for (int i = 0; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            dp[i][j] = MIN_VAL;
        }
    }

    dp[0][1] = 0;

    for (int n = 1; n <= N; n++) {
        for (int m = 1; m <= M; m++) {
            if (dp[n-1][m] != MIN_VAL)
                dp[n][m] = max(dp[n-1][m] + num[n], dp[n][m]);
        

            for (int i = 1; i < n-1; i++) {
                if (dp[i][m-1] == MIN_VAL)
                    continue;

                dp[n][m] = max(dp[i][m-1] + num[n], dp[n][m]);
            }
        }
    }

    int ans = MIN_VAL;

    for (int i = 1; i <= N; i++) {
        ans = max(dp[i][M], ans);
    }

    cout << ans;

    return 0;
}