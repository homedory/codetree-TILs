#include <iostream>
using namespace std;

#define MAX_N 100005

int main() {
    int n, q;
    int arr[MAX_N], L[MAX_N], R[MAX_N];

    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    L[0] = 0;
    for (int i = 1; i <= n; i++) {
        L[i] = max(L[i-1], arr[i]);
    }

    R[n+1] = 0;
    for (int i = n; i >= 1; i--) {
        R[i] = max(R[i+1], arr[i]);
    }

    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        cout << max(L[a - 1], R[b + 1]) << "\n";
    }
    
    return 0;
}