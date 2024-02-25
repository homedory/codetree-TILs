#include <iostream>
using namespace std;

long long n, k;

long long CountOrder(long long x) {
    long long cnt = 0;
    for (int i = 1; i <= n; i++) {
        cnt += min(n, x / i);
    }

    return cnt;
}

int main() {
    

    cin >> n;
    cin >> k;

    long long l = 1, r = n * n;
    long long min_num = r;

    while(l <= r) {
        long long mid = (l + r) / 2;

        if (CountOrder(mid) >= k) {
            r = mid - 1;
            min_num = min(min_num, mid);
        }
        else {
            l = mid + 1;
        }
    }

    cout << min_num;
    
    return 0;
}