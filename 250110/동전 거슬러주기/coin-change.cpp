#include <iostream>

using namespace std;

#define MAX_N 10005
#define INF 1000000000

int N, M;
int coin[100];
int dp[MAX_N];

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> coin[i];
    }

    // initialize
    for (int i = 1; i < MAX_N; i++)
        dp[i] = INF;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= M; j++) {
            if (coin[i] > j)
                continue;
            
            dp[j] = min(dp[j - coin[i]] + 1, dp[j]);
        }
    }

    if (dp[M] == INF)
        cout << -1;
    else
        cout << dp[M];

    return 0;
}
