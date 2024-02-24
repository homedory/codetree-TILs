#include <iostream>
using namespace std;

long long GetNumber(long long n) {

    return n - n / 3 - n / 5 + n / 15;
}

int main() {
    int N;

    cin >> N;

    long long l = 1, r = 4000000000;

    while(l <= r) {
        long long mid = (l + r) / 2;

        if (GetNumber(mid) == N) {
            cout << mid;
            break;
        }

        if (GetNumber(mid) < N) {
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }
    
    return 0;
}