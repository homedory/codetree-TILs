#include <iostream>

using namespace std;

int n;
int arr[1005];
int dp[1005];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = n-1; i >= 0; i--) {
        for (int j = min(n-1, i + arr[i]); j > i; j--) {
            dp[i] = max(dp[i], dp[j] + 1);
        }
    }

    cout << dp[0];

    return 0;
}
