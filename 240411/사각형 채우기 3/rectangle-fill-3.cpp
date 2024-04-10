#include <iostream>
using namespace std;

#define MAX_N 1005
#define MOD 1000000007

int dp[MAX_N], sum[MAX_N];

int main() {
    int N;

    cin >> N;

    dp[1] = 2;
    dp[2] = 7;
    sum[1] = 2;
    sum[2] = 9;

    for (int i = 3; i <= N; i++) {
        dp[i] = ((2 * sum[i - 1]) % MOD + dp[i - 2] + 2) % MOD;
        sum[i] = (sum[i - 1] + dp[i]) % MOD; 
    }

    cout << dp[N];

    return 0;
}