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
        for (int j = 0; j < N; j++) {
            if (coin[j] > i)
                continue;
            
            dp[i] = max(dp[i-coin[j]] + 1, dp[i]);
        }
    }

    cout << (dp[M] == 0 ? -1 : dp[M]);

    return 0;
}
