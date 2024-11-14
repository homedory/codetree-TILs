#include <iostream>
using namespace std;

#define MAX_N 105

int N;
int dp[MAX_N][MAX_N];

void initialize() {
    for (int i = N-1; i >= 1; i--) 
        dp[1][i] += dp[1][i+1];
    
    for (int i = 2; i <= N; i++) 
        dp[i][N] += dp[i-1][N];
}

int main() {
    cin >> N;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> dp[i][j];
        }
    }

    initialize();

    for (int i = 2; i <= N; i++) {
        for (int j = N-1; j >= 1; j--) {
            dp[i][j] += min(dp[i-1][j], dp[i][j+1]);
        }
    }

    cout << dp[N][1];
    
    return 0;
}