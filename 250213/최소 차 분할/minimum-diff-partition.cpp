#include <iostream>

using namespace std;

int n;
int arr[100];
int dp[100005];

int main() {
    int sum = 0;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }

    int target_num = sum / 2;

    for (int i = 1; i <= target_num; i++)
        dp[i] = -1;

    for (int i = 0; i < n; i++) {
        for (int j = target_num; j > 0; j --) {
            if (j < arr[i] || dp[j-arr[i]] == -1)
                continue;
            
            dp[j] = 1;
        }
    }

    int max_num = 0;
    for (int i = 0; i <= target_num; i++) {
        if (dp[i] == -1)
            continue;
        
        max_num = i;
    }

    int ans = sum - 2 * max_num;

    cout << ans;

    return 0;
}
