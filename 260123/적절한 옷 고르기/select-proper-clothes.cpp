#include <iostream>
#include <math.h>
using namespace std;

int s[205], e[205], v[205];
int dp[205][205];

int main() {
    int N, M;
    
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> s[i] >> e[i] >> v[i];
    }

    for (int d = 2; d <= M; d++) {
        for (int i = 1; i <= N; i++) {
            if (d < s[i] || d > e[i])
                    continue;
            
            for (int j = 1; j <= N; j++) {
                if (d - 1 < s[j] || d - 1 > e[j])
                    continue;
                    
                int diff = abs(v[i] - v[j]);
                dp[d][i] = max(dp[d][i], dp[d-1][j] + diff);
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= N; i++) {
        ans = max(ans, dp[M][i]);
    }

    cout << ans;
    
    return 0;
}