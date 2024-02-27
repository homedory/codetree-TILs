#include <iostream>
#include <climits>
using namespace std;

#define MAX_N 100005

int n;
int v[MAX_N];
long long x[MAX_N];

bool IsPossible(long long t) {
    long long start = LONG_MIN, end = LONG_MAX;

    for (int i = 0; i < n; i++) {
        start = max(start, x[i] - v[i] * t);
        end = min(end, x[i] + v[i] * t);
    }

    return start <= end;
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x[i];
        x[i]  = x[i] * 100000;
    }

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    long long l = 1, r = LONG_MAX;
    long long t;

    while(l <= r) {
        long long mid = (l + r) / 2;

        if (IsPossible(mid)) {
            r = mid - 1;
            t = mid;
        }
        else {
            l = mid + 1;
        }
    }

    t = (t % 10 >= 5) ? t / 10 + 1 : t / 10;

    double ans = (double) t / 10000;
    
    cout << fixed;
    cout.precision(4);

    cout << ans;

    return 0;
}