#include <iostream>
#include <unordered_map>
using namespace std;

#define MAX_N 100005

int main() {
    int n, k;
    int arr[MAX_N];
    unordered_map<int,int> num_cnt;

    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    int j = 0;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        while(j + 1 <= n && (num_cnt.find(arr[j + 1]) == num_cnt.end() || num_cnt[arr[j + 1]] < k)) {
            num_cnt[arr[j + 1]] += 1;
            j++;
        }
        ans = max(ans, j - i + 1);

        num_cnt[arr[i]] -= 1;
    }

    cout << ans;

    return 0;
}