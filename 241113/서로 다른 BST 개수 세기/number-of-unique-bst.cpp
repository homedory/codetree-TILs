#include <iostream>
using namespace std;

#define MAX_N 20

int dp[MAX_N];

int main() {
    int N;
    cin >> N;

    dp[0] = 1;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= i;j++) {
            dp[i] += dp[j-1] * dp[i-j];
        }
    }

    cout << dp[N];

    return 0;
}