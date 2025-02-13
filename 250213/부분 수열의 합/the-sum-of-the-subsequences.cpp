#include <iostream>

using namespace std;

int n, m;
int A[100];
int dp[10005];

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    dp[0] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = m; j >= 0; j--) {
            if (j < A[i] || dp[j-A[i]] == 0)
                continue;
            
            dp[j] = 1;
        }
    }

    cout << (dp[m] == 1 ? "Yes" : "No");

    return 0;
}
