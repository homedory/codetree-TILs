#include <iostream>
#include <climits>

using namespace std;

int n;
int arr[100000];
int dp[100000];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    dp[0] = arr[0];

    for (int i = 1; i < n; i++) 
        dp[i] = max(dp[i-1], 0) + arr[i];
    

    int ans = INT_MIN;

    for (int i = 0; i < n; i++)
        ans = max(ans, dp[i]);

    cout << ans;


    return 0;
}
