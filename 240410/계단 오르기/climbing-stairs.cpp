#include <iostream>
using namespace std;

#define MAX_N 1005

int dp[MAX_N];

int main() {
    int N;

    cin >> N;

    dp[2] = 1;
    dp[3] = 1;

    for (int i = 4; i <= N; i++) {
        dp[i] = (dp[i - 2] + dp[i - 3]) % 10007;
    }

    cout << dp[N];
    
    return 0;
}