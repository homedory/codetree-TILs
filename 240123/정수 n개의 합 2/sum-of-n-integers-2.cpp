#include <iostream>
using namespace std;
#define MAX_N 100005

int main() {
    int n, k;
    int arr[MAX_N], prefix_sum[MAX_N];
    int ans = -2000000000;
    cin >> n >> k;

    prefix_sum[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        prefix_sum[i] = prefix_sum[i-1] + arr[i];
    }

    for (int i = 0; i + k <= n; i++) {
        ans = max(ans, prefix_sum[i + k] - prefix_sum[i]);
    }

    cout << ans;
    return 0;
}