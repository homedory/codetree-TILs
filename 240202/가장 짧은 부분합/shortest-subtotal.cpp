#include <iostream>
using namespace std;

#define MAX_N 100005

int main() {
    int n, s;
    int arr[MAX_N];

    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int x = 0, j = 0;
    int sum_value = 0;
    
    while(x < n && sum_value + arr[x] < s) {
        sum_value += arr[x];
        x++;
    }

    int ans = x + 1;
    for (int i = x; i < n; i++) {
        sum_value += arr[i];
        while(j + 1 <= i && sum_value - arr[j] >= s) {
            sum_value -= arr[j];
            j++;
        }

        ans = min(ans, i - j + 1);

    }

    if (ans == n + 1) {
        cout << -1;
    }
    else {
        cout << ans;
    }


    return 0;
}