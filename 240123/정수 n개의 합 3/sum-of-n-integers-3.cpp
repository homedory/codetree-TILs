#include <iostream>
using namespace std;
#define MAX_N 105

int arr[MAX_N][MAX_N], sum[MAX_N][MAX_N];

int main() {
    int n, k, ans = 0;
    
    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j =1; j <= n; j++) {
            sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + arr[i][j];
        }
    }

    for (int i = 0; i + k <= n; i++) {
        for (int j = 0; j + k <= n; j++) {
            int s = sum[i+k][j+k] - sum[i+k][j] - sum[i][j+k] + sum[i][j];
            ans = max(ans, s);
        }
    }

    cout << ans;
    return 0;
}