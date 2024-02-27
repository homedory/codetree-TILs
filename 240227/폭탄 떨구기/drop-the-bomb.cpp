#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_N 50005

int N, K;
int arr[MAX_N];

bool IsPossible(int r) {
    int idx = 0;
    int cnt = 0;

    while(idx < N) {
        int end = arr[idx] + 2 * r;
        idx = upper_bound(arr, arr + N, end) - arr;
        cnt++;
    }

    return cnt <= K;
}

int main() {
    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + N);


    int l = 1, r = 1000000000;
    int ans = 1000000000;
    while(l <= r) {
        int mid = (l + r) / 2;

        if (IsPossible(mid)) {
            r = mid - 1;
            ans = mid;
        }
        else {
            l = mid + 1;
        }
    }

    cout << ans;

    
    return 0;
}