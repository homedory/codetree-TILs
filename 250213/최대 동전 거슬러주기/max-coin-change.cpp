#include <iostream>

using namespace std;

int N, M;
int coin[100];
int dp[10005];

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> coin[i];
    }

    for (int i = 1; i <= M; i++) {
        dp[i] = -1;
        for (int j = 0; j < N; j++) {
            if (coin[j] > i || dp[i-coin[j]] == -1)
                continue;
            
            dp[i] = max(dp[i-coin[j]] + 1, dp[i]);
        }
    }

    cout << dp[M];

    return 0;
}
