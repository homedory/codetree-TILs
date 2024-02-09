#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_N 100005

int arr[MAX_N];

int main() {
    int n;

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    int s = 1, e = n;
    int ans = 2000000000;

    while(s < e) {
        ans = min(ans, abs(arr[s] + arr[e]));

        if (arr[s] + arr[e] > 0) {
            e--;
        }
        else {
            s++;
        }
    }

    cout << ans;
    
    return 0;
}