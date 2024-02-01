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

    int ans = x;
    for (int i = x; i < n; i++) {
        sum_value += arr[i];
        while(j + 1 <= i && sum_value - arr[j + 1] >= s) {
            sum_value -= arr[j + 1];
            j++;
        }

        ans = min(ans, i - j + 1);

    }

    if (ans == n) {
        cout << (sum_value >= s ? ans : -1);
    }
    else {
        cout << ans;
    }


    return 0;
}