#include <iostream>

using namespace std;

int N, M;
int w[100], v[100];
int dp[10005];

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> w[i] >> v[i];
    }

    for (int i = 1; i <= M; i++) {
        for (int j = 0; j < N; j++) {
            if (i < w[j])
                continue;
            
            dp[i] = max(dp[i], dp[i-w[j]] + v[j]);
        }
    }

    int ans = 0;

    for (int i = 0; i <= M; i++)
        ans = max(ans, dp[i]);
        
    cout << ans;

    return 0;
}
