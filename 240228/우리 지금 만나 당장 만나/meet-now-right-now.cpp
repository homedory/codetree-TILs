#include <iostream>
#include <climits>
using namespace std;

#define MAX_N 100005

int n;
int v[MAX_N], x[MAX_N];

bool IsPossible(double t) {
    double start = x[0] - v[0] * t, end = x[0] + v[0] * t;

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
    }

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    double l = 0, r = 1000000000;
    double ans;

    while(l <= r) {
        long long mid = (l + r) / 2;

        if (IsPossible(mid)) {
            r = mid - 1;
            ans = mid;
        }
        else {
            l = mid + 1;
        }
    }
    
    cout << fixed;
    cout.precision(4);

    cout << ans;

    return 0;
}