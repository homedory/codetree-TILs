#include <iostream>
using namespace std;

#define MAX_N 1005

int dp[MAX_N];

int main() {
    int n;
    cin >> n;

    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = (dp[i-2] * 2 + dp[i-1]) % 10007;
    }

    cout << dp[n];
    
    return 0;
}