#include <iostream>
using namespace std;

#define MAX_LEN 200
#define MAX_N 100

int main() {
    int N;
    int red_card[MAX_LEN], blue_card[MAX_LEN];
    int dp[MAX_N] = { 0 };

    cin >> N;
    
    int len = 2 * N;
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