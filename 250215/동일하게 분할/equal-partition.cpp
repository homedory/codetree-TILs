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

    dp[0] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = sum; j >= 0; j--) {
            if (j < arr[i] || dp[j-arr[i]] != 1)
                continue;
            
            dp[j] = 1;
        }
    }

    if (sum % 2 == 1)
        cout << "No";
    else
        cout << (dp[sum/2] == 1 ? "Yes" : "No");

    return 0;
}
