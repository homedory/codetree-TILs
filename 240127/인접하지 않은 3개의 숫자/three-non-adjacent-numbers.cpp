#include <iostream>
using namespace std;

#define MAX_N 100005

int main() {
    int n;
    int arr[MAX_N], L[MAX_N], R[MAX_N];

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    L[0] = 0;
    for (int i = 1; i < n; i++) {
        L[i] = max(L[i-1], arr[i]);
    }

    R[n+1] = 0;
    for (int i = n; i >= 1; i--) {
        R[i] = max(R[i+1], arr[i]);
    }

    int ans = 0;
    for (int i = 3; i < n - 1; i++) {
        ans = max(ans, arr[i] + L[i - 2] + R[i + 2]);
    }

    cout << ans;

    return 0;
}