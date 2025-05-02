#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, M;
    int arr[105];
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    vector<vector<long long>> dp(N, vector<long long>(41, 0));

    dp[0][20+arr[0]] = 1;
    dp[0][20-arr[0]] = 1;

    for (int i = 1; i < N; i++) {
        for (int j = 0; j <= 40; j++) {
            if (j >= arr[i]) {
                dp[i][j] += dp[i-1][j-arr[i]];
            }
            if (j + arr[i] <= 40) {
                dp[i][j] += dp[i-1][j+arr[i]];
            }
        }
    }

    cout << dp[N-1][M + 20];

    return 0;
}