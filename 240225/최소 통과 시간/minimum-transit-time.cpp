#include <iostream>
using namespace std;

#define MAX_N 100005

int main() {
    int n, m;
    int arr[MAX_N];

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> arr[i];
    }

    int l = 1, r = 1000000000;
    int ans = 1000000000;

    while(l <= r) {
        int mid = (l + r) / 2;

        long long cnt = 0;

        for (int i = 0; i < m; i++) {
            cnt += mid / arr[i];
        }

        if (cnt >= n) {
            r = mid - 1;
            ans = min(ans, mid);
        }
        else {
            l = mid + 1;
        }
    }

    cout << ans;


    return 0;
}