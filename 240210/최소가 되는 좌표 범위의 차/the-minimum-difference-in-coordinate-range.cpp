#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

#define MAX_N 100005

int main() {
    int N, D;
    pair<int,int> arr[MAX_N];
    map<int,int> x_cnt;

    cin >> N >> D;

    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        arr[i] = make_pair(y, x);
        x_cnt[x] += 1;
    }

    sort(arr, arr + N);
    int ans = 1000000;

    int j = 0;

    for (int i = 0; i < N; i++) {
        while(j + 1 < N && arr[j].first - arr[i].first < D) {
            x_cnt[arr[j].second] -= 1;
            if (x_cnt[arr[j].second] == 0) {
                x_cnt.erase(arr[j].second);
            }
            j++;
        }

        if (arr[j].first - arr[i].first < D) 
            continue;

        map<int,int>::iterator itlow = x_cnt.lower_bound(arr[i].second);

        if (itlow == x_cnt.end()) {
            ans = min(ans, arr[i].second - (--itlow)->first);
        }
        else if (itlow != x_cnt.begin()) {
            int a = itlow->first - arr[i].second;
            int b = arr[i].second - (--itlow)->first;
            int range = min(a, b);
            ans = min(ans, range);
        }
        else {
            ans = min(ans, itlow->first - arr[i].second);
        }
    }

    cout << (ans == 1000000 ? -1 : ans);

    return 0;
}