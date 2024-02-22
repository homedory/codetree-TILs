#include <iostream>
using namespace std;

#define MAX_N 1000005

int main() {
    int n, k;
    int arr[MAX_N];

    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    int cnt = 0;
    int j = 1;
    arr[0] = 2;
    int ans = n + 1; 
    for (int i = 1; i <= n; i++) {
        if (arr[i] == 1) {
            cnt++;
            while(cnt >= k && j + 1 <= n) {
                if (cnt == k) {
                    if (arr[j] == 2) {
                        j++;
                    }
                    else {
                        break;
                    }
                }
                else {
                    if (arr[j] == 1)
                        cnt--;
                    j++;
                }
            }
        }
        
        if (cnt == k) {
            ans = min(ans, i - j + 1);
        }
    }

    if (ans == n + 1) {
        cout << -1;
    }
    else {
        cout << ans;
    }

    return 0;
}