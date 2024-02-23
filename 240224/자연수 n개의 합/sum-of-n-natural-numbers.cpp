#include <iostream>
using namespace std;


int main() {
    long long s;

    cin >> s;

    long long l = 1, r = s;

    long long ans = 0;
    while(l <= r) {
        long long mid = (l + r) / 2;

        if (mid * (mid + 1) / 2 <= s) {
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