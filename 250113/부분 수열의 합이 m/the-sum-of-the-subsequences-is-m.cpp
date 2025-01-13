#include <iostream>

using namespace std;

#define INF 2000000000

int n, m;
int A[100];
int dp[10005];

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    //initialize
    for (int i = 0; i <= 10000; i++) 
        dp[i] = INF;
    
    dp[0] = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = m; j >= 0; j--) {
            if (j < A[i])
                continue;
            
            dp[j] = min(dp[j], dp[j - A[i]] + 1);
        }
    }

    if (dp[m] == INF)
        cout << -1;
    else
        cout << dp[m];

    return 0;
}
