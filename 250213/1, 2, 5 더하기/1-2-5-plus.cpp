#include <iostream>

using namespace std;

int n;
int dp[1005];

int main() {
    cin >> n;

    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    dp[4] = 5;
    
    for (int i = 5; i <= n; i++) {
        dp[i] = (dp[i-1] + dp[i-2] + dp[i-5]) % 10007;
    }

    cout << dp[n];

    return 0;
}
