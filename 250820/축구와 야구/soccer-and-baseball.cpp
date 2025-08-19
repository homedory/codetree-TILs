#include <iostream>
using namespace std;



int main() {
    int N;
    int dp[20][20][2];
    int ability[1005][2];

    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 20; ++j) {
            dp[i][j][0] = -1;
            dp[i][j][1] = -1;
        }
    }
    dp[0][0][0] = 0;
    dp[0][0][1] = 0;
    
    cin >> N;

    for (int i = 0; i < N; ++i) {
        cin >> ability[i][0] >> ability[i][1];
    }

    for (int i = 0; i < N; ++i) {
        for (int s = 0; s <= 11; ++s) {
            for (int b = 0; b <= 9; ++b) {
                if (dp[s][b][(i+1)%2] < 0)
                    continue;
                
                dp[s+1][b][i%2] = max(dp[s+1][b][i%2], dp[s][b][(i+1)%2] + ability[i][0]);
                dp[s][b+1][i%2] = max(dp[s][b+1][i%2], dp[s][b][(i+1)%2] + ability[i][1]);
                dp[s][b][i%2] = max(dp[s][b][i%2], dp[s][b][(i+1)%2]);
            }
        }
    }

    cout << dp[11][9][(N-1)%2];
    
    return 0;
}