#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_N 100005

int N, M, C;
int arr[MAX_N];

bool IsPossible(int d) {
    int bus_cnt = 1, people_cnt = 0;

    int idx = 0;

    for (int i = 0; i < N; i++) {
        if (people_cnt < C && arr[i] - arr[idx] <= d) {
            people_cnt++;
        }
        else {
            idx = i;
            bus_cnt++;
            people_cnt = 0;
        }
    }

    return bus_cnt <= M;
}

int main() {
    
    cin >> N >> M >> C;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + N);

    int l = 1, r = 1000000000;
    int ans;

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