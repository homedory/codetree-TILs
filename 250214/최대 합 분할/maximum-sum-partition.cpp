#include <iostream>

using namespace std;

#define MAX_M 100000
#define OFFSET 100000

int n;
int arr[101];
int dp[100][MAX_M + OFFSET + 1];

int main() {
    int sum = 0;

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }

    for (int i = 0; i <= n; i++) 
        for(int j = -sum; j <= sum; j++)
            dp[i][j + OFFSET] = -1;

    dp[0][0 + OFFSET] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = -sum; j <= sum; j++) {
            if (dp[i-1][j - arr[i] + OFFSET] != -1)
                dp[i][j + OFFSET] = max(dp[i][j + OFFSET], dp[i-1][j - arr[i] + OFFSET] + arr[i]);
            
            if (j + arr[i] <= sum && dp[i-1][j + arr[i] + OFFSET] != -1)
                dp[i][j + OFFSET] = max(dp[i][j + OFFSET], dp[i-1][j + arr[i] + OFFSET]);
            
            dp[i][j + OFFSET] = max(dp[i][j + OFFSET], dp[i-1][j + OFFSET]);
        }
    }

    cout << dp[n][0 + OFFSET];
    

    return 0;
}
