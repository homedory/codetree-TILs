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

    for (int i = 1; i <= M; i++)
        dp[i] = -1;

    for (int i = 0; i < N; i++) {
        for (int j = M; j >= 0; j--) {
            if (j < w[i] || dp[j-w[i]] == -1)
                continue;
            
            dp[j] = max(dp[j], dp[j-w[i]] + v[i]);
        }
    }

    int ans = 0;
    for (int i = 0; i <= M; i++) 
        ans = max(ans, dp[i]);
    
    cout << ans;

    
    return 0;
}
