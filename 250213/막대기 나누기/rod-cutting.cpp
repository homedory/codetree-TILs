#include <iostream>

using namespace std;

int n;
int profit[105];
int dp[105];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> profit[i];
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i] = max(dp[i], dp[i-j] + profit[j]);
        }
    }

    cout << dp[n];

    return 0;
}
