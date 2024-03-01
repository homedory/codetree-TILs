#include <iostream>
using namespace std;

int main() {
    int n, k;
    int c[10];

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    int cnt = 0;

    for (int i = n - 1; i >= 0; i--) {
        cnt += k / c[i];
        k = k % c[i];
    }

    cout << cnt;

    return 0;
}