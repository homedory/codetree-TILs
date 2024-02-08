#include <iostream>
using namespace std;

#define MAX_N 100005

int main() {
    int n, m;
    int arr[MAX_N];

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int sum = 0, j = 0;
    int ans = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];
        if (sum == m)
            ans++;
            
        while(sum > m) {
            sum -= arr[j];
            if (sum == m)
                ans++;
            
            j++;
        }
    }

    cout << ans;

    return 0;
}