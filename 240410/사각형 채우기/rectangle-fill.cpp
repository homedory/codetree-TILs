#include <iostream>
using namespace std;

#define MAX_N 1005

int dp[MAX_N];

int main() {
    int N;

    cin >> N;

    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= N; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
    }

    cout << dp[N];

    return 0;
}