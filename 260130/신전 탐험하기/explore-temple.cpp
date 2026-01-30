#include <iostream>
using namespace std;

int main() {
    int N;
    int gem[1005][1005], dp[1005][1005];

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> gem[i][0] >> gem[i][1] >> gem[i][2];
    }
    for (int i = 0; i < 3; i++) {
        dp[0][i] = gem[0][i];
    }
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                if (j == k)
                    continue;
                
                dp[i][j] = max(dp[i][j], dp[i-1][k] + gem[i][j]);
            }
        }
    }
    
    int ans = 0;
    for (int i = 0; i < 3; i++) {
        ans = max(ans, dp[N-1][i]);
    }

    cout << ans;

    return 0;
}