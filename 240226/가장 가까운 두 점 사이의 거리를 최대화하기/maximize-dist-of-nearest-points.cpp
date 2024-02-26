#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

#define MAX_N 100005

pair<int,int> arr[MAX_N];

int n;

bool IsPossible(int dist) {
    int prev = INT_MIN;

    for (int i = 0; i < n; i++) {
        int x1 = arr[i].first, x2 = arr[i].second;

        if (prev + dist <= x2) {
            prev = max(prev + dist, x1);
        }
        else {
            return false;
        }
    }

    return true;
}

int main() {
    int x1, x2;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x1 >> x2;
        arr[i] = make_pair(x1, x2);
    }

    sort(arr, arr + n);

    int l = 0, r = INT_MAX;
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