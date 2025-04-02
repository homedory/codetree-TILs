#include <iostream>
#include <climits>
using namespace std;

#define MAX_LEN 205
#define MAX_N 105

int main() {
    int N;
    int red_card[MAX_LEN], blue_card[MAX_LEN];
    int dp[MAX_N];


    cin >> N;

    dp[0] = 0;
    for (int i = 1; i <= N; ++i) {
        dp[i] = INT_MIN;
    }
    
    int len = N << 1;
    for (int i = 0; i < len; ++i) {
        cin >> red_card[i] >> blue_card[i];
    }

    for (int i = 0; i < len; ++i) {
        for (int j = min(i + 1, N); j > 0; --j) {
            dp[j] = max(dp[j-1] + red_card[i], dp[j] + blue_card[i]);
        }

        dp[0] += blue_card[i];
    }

    cout << dp[N];

    return 0;
}