#include <iostream>
using namespace std;

#define MAX_N 100005

int n, m;
int arr[MAX_N];

int lower_bound(int x) {
    int l = 1, r = n;
    int min_idx = n + 1;

    while(l <= r) {
        int mid = (l + r) / 2;

        if (arr[mid] >= x) {
            r = mid - 1;
            min_idx = min(min_idx, mid);
        }
        else {
            l = mid + 1;
        }
    }

    return min_idx;
}

int main() {
    
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        int idx = lower_bound(x);
        if (arr[idx] == x) {
            cout << idx << "\n";
        }
        else {
            cout << -1 << "\n";
        }
    }

    return 0;
}