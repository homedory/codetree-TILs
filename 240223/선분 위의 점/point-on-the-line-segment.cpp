#include <iostream>
#include <algorithm>
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

int upper_bound(int x) {
    int l = 1, r = n;
    int min_idx = n + 1;

    while(l <= r) {
        int mid = (l + r) / 2;

        if (arr[mid] > x) {
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

    sort(arr + 1, arr + n + 1);

    for (int i = 0; i < m; i++) {
        int s, e;
        cin >> s >> e;

        cout << upper_bound(e) - lower_bound(s) << "\n";
    }

    return 0;
}