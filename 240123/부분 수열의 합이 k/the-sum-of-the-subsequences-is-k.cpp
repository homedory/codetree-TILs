#include <iostream>
#include <set>
using namespace std;
#define MAX_N 1005

int main() {
    int n, k, ans = 0;
    int arr[MAX_N], prefix_sum[MAX_N];
    set <int> s;
    cin >> n >> k;

    prefix_sum[0] = 0;
    s.insert(0);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        prefix_sum[i] = prefix_sum[i-1] + arr[i];
        if (s.find(prefix_sum[i] - k) != s.end()) {
            ans++;
        }
        s.insert(prefix_sum[i]);
    }

    cout << ans;


    return 0;
}