#include <iostream>
using namespace std;

long long GetNumber(long long n) {

    return n - n / 3 - n / 5 + n / 15;
}

int main() {
    int N;

    cin >> N;

    long long l = 1, r = 4000000000;
    long long ans = 4000000000;

    while(l <= r) {
        long long mid = (l + r) / 2;

        if (GetNumber(mid) >= N) {
            r = mid - 1;
            ans = min(ans, mid);
        }
        else {
            l = mid + 1;
        }
    }

    cout << ans;


    return 0;
}