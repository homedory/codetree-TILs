#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

#define MAX_N 100005

int N, M;
pair<long long, long long> arr[MAX_N];

bool IsPossible(long long x) {

    int cnt = 0;
    long long prev = LONG_MIN;
    
    for (int i = 0; i < M; i++) {
        long long a = arr[i].first, b = arr[i].second;

        while(prev + x <= b) {
            cnt++;
            prev = max(a, prev + x);
        }
    }

    return cnt >= N;
}

int main() {
    long long a, b;

    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        arr[i] = make_pair(a, b);
    }

    sort(arr, arr + M);

    long long l = 0, r = LONG_MAX;
    
    long long ans = 0;

    while(l <= r) {
        long long mid = (l + r) / 2;

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