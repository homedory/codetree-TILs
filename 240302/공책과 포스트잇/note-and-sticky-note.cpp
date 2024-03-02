#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_N 100005

int N, K, L;
int c[MAX_N];

bool IsPossible(int h) {
    int cnt = 0;
    long long remain = (long long) K * L;

    for (int i = 0; i < N; i++) {
        if (c[i] >= h) {
            cnt++;
        }
        else if (h - c[i] <= K && remain >= h - c[i]) {
            remain -= h - c[i];
            cnt++;
        }
        else {
            break;
        }
    }

    return cnt >= h;
}

int main() {
    cin >> N >> K >> L;

    for (int i = 0; i < N; i++) {
        cin >> c[i];
    }

    sort(c, c + N, greater<int>());

    int l = 0, r = N;
    int ans;

    while(l <= r) {
        int mid = (l + r) / 2;

        if (IsPossible(mid)) {
            l = mid + 1;
            ans = mid;
        }
        else {
            r = mid - 1;
        }
    }

    cout << ans;

    return 0;
}