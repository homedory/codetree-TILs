#include <iostream>
using namespace std;

#define MAX_N 10005

int n, m;
int arr[MAX_N];

bool IsPossible(int x) {
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        cnt += (arr[i] / x);
    }
    
    return cnt >= m;
}

int main() {

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int ans = 0;
    int l = 1, r = 100000;

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