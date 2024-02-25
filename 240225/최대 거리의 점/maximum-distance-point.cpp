#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_N 200005

int n, m;
int diff[MAX_N], arr[MAX_N];

bool IsPossible(int bound) {
    int cnt = 0;
    int sum = 0;
    for (int i = 0; i < n - 1; i++) {
        sum += diff[i];
        if (sum >= bound) {
            sum = 0;
            cnt++;
        }
    }

    return cnt >= m - 1;
}

int main() {
    
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    for (int i = 0; i < n - 1; i++) {
        diff[i] = arr[i + 1] - arr[i];
    }

    int l = 1, r = 1000000000;

    int ans = 0;
    while(l <= r) {
        int mid = (l + r) / 2;

        if (IsPossible(mid)) {
            l = mid + 1;
            ans = max(ans, mid);
        }
        else {
            r = mid - 1;
        }
    }

    cout << ans;


    return 0;
}