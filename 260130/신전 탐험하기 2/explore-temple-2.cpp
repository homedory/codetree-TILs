#include <iostream>
using namespace std;

int dp[3][1005][1005];

int main() {

    int N;
    int gem[1005][1005];
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> gem[i][0] >> gem[i][1] >> gem[i][2];
    }
    
    for (int i = 0; i < 3; i++) {
        dp[i][0][i] = gem[0][i];
    }

    for (int i = 1; i < N-1; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                for (int l = 0; l < 3; l++) {
                    if (k == l || dp[j][i-1][l] == 0)
                        continue;
                    
                    dp[j][i][k] = max(dp[j][i][k], dp[j][i-1][l] + gem[i][k]);
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                if (i == k || j == k)
                    continue;
                
                ans = max(ans, dp[i][N-2][j] + gem[N-1][k]);
            }
        }
    }

    cout << ans;

    return 0;
}