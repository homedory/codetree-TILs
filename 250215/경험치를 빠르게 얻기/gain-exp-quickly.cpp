#include <iostream>

using namespace std;

#define MAX_M 1000000
#define MAX_VAL 100000

int n, m;
int e[100], t[100];
int dp[MAX_M + 1];

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> e[i] >> t[i];
    }

    for (int i = 1; i <= m; i++)
        dp[i] = MAX_VAL;

    for (int i = 0; i < n; i++) {
        for (int j = m; j >= 0; j--) {
            dp[min(m, j + e[i])] = min(dp[min(m, j + e[i])], dp[j] + t[i]);
        }
    }

    cout << (dp[m] == MAX_VAL ? -1 : dp[m]);

    return 0;
}
