#include <iostream>
#include <algorithm>
using namespace std;

long long m;

int BinarySearchCnt(long long x) {
    long long l = 1, r = m;
    int cnt = 1;

    while(l <= r) {
        long long mid = (l + r) / 2;

        if (mid == x)
            break;
        
        if (mid < x) {
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }

        cnt++;
    }

    return cnt;
}

int main() {
    long long a, b;

    cin >> m;
    cin >> a >> b;

    int max_cnt = 0, min_cnt = m;

    for (long long i = a; i <= b; i++) {
        int cnt = BinarySearchCnt(i);

        max_cnt = max(max_cnt, cnt);
        min_cnt = min(min_cnt, cnt);
    }

    cout << min_cnt << " " << max_cnt;

    return 0;
}