#include <iostream>
using namespace std;

#define MAX_N 100005

int main() {
    int n;
    int arr[MAX_N];

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int sum = 0, ans = -1000;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        ans = max(ans, sum);

        if (sum < 0) {
            sum = 0;
        }
    }

    cout << ans;

    return 0;
}