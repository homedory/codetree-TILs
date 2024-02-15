#include <iostream>
#include <unordered_map>
using namespace std;

#define MAX_N 100005

int main() {
    int n, m;
    int arr[MAX_N];
    unordered_map<int,int> cnt1, cnt2;

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        cnt1[arr[i]] += 1;
    }

    int ans = MAX_N;
    int j = 0;

    for (int i = 1; i <= n; i++) {
        cnt2[arr[i]] += 1;
        cnt1[arr[i]] -= 1;
        if (cnt1[arr[i]] == 0) {
            cnt1.erase(arr[i]);
        }
        while(j + 1 <= n && cnt2[arr[j + 1]] > 1) {
            cnt2[arr[j + 1]] -= 1;
            cnt1[arr[j + 1]] += 1;
        
            if (cnt2[arr[j + 1]] == 0) {
                cnt2.erase(arr[j + 1]);
            }
            j++;
        }

        if (cnt1.size() == m && cnt2.size() == m) {
            ans = min(ans, i - j);
        }
    }

    cout << ((ans == MAX_N) ? -1 : ans);


    return 0;
}