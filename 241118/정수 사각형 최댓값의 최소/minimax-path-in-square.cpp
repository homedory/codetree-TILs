#include <iostream>
using namespace std;

#define MAX_N 105

int N;
int dp[MAX_N][MAX_N];

void initialize() {
    for (int i = 2; i <= N; i++) {
        dp[i][1] = max(dp[i][1], dp[i-1][1]);
        dp[1][i] = max(dp[1][i], dp[1][i-1]);
    }
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
        for (int j = 2; j <= N; j++) {
            dp[i][j] = max(min(dp[i-1][j], dp[i][j-1]), dp[i][j]);
        }
    }

    cout << dp[N][N];


    return 0;
}