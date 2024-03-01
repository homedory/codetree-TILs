#include <iostream>
#include <climits>
using namespace std;

#define MAX_N 100005

int main() {
    int n;
    int price [MAX_N];
    int left_min[MAX_N], right_max[MAX_N];

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> price[i];
    }

    right_max[n] = INT_MIN;
    for (int i = n - 1; i >= 0; i--) {
        right_max[i] = max(right_max[i + 1], price[i]);
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, right_max[i] - price[i]);
    }

    cout << ans;


    return 0;
}