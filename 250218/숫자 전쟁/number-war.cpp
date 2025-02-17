#include <iostream>

using namespace std;

int n;
int first_cards[1001];
int second_cards[1001];
int dp[1001][1001];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> first_cards[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> second_cards[i];
    }

    for (int i = 0; i <= n; i++) 
        for (int j = 0; j <= n; j++)
            dp[i][j] = -1;
        
    dp[0][0] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dp[i-1][j-1] == -1)
                continue;

            if (first_cards[i] > second_cards[j])
                dp[i-1][j] = max(dp[i-1][j], dp[i-1][j-1] + second_cards[j]);
            
            else if (first_cards[i] < second_cards[j])
                dp[i][j-1] = max(dp[i][j-1], dp[i-1][j-1]);
            
            dp[i][j] = max(dp[i][j], dp[i-1][j-1]);
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            ans = max(ans, dp[i][j]);

    cout << ans;

    return 0;
}
