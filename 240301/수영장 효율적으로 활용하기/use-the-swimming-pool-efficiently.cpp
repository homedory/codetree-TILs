#include <iostream>
#include <climits>
using namespace std;

#define MAX_N 100005

int n, m;
int T[MAX_N];

bool IsPossible(int t) {
    int cnt = 1;
    int sum = 0;

    for (int i = 0; i < n; i++) {
        if (T[i] >= t)
            return false;

        if (sum + T[i] <= t) {
            sum += T[i];
        }
        else {
            cnt++;
            sum = T[i];
        }
    }

    return cnt <= m;
}

int main() {
    cin >> n >> m;
    
    for (int i = 0; i < n; i++) {
        cin >> T[i];
    }

    int l = 1, r = INT_MAX;
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