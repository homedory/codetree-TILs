#include <iostream>
#include <set>
using namespace std;

int main() {
    int n;
    int arr[100005], sum[100005];
    set<pair<int,int>> s;
    double ans = 0;

    cin >> n;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> arr[i];
        s.insert(make_pair(arr[i], i));
    }

    int total = 0;
    for (int i = n - 1; i >= 0; i--) {
        total += arr[i];
        sum[i] = total;
    }

    s.erase(make_pair(arr[0], 0));
    for (int i = 0; i < n - 2; i++) {
        s.erase(make_pair(arr[i], i));
        double avg = (sum[i] - s.begin()->first - arr[i]) / (double) (n - 2 - i);
        ans = max(ans, avg);
    }
    cout << fixed;
    cout.precision(2);

    cout << ans;
    return 0;
}