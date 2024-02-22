#include <iostream>
#include <algorithm>
using namespace std;

int m;

int BinarySearchCnt(int x) {
    int l = 1, r = m;
    int cnt = 1;

    while(l <= r) {
        int mid = (l + r) / 2;

        if (mid == x)
            break;
        
        if (mid < x) {
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }

        cnt++;
    }

    return cnt;
}

int main() {
    int a, b;

    cin >> m;
    cin >> a >> b;

    int max_cnt = 0, min_cnt= m;

    for (int i = a; i <= b; i++) {
        int cnt = BinarySearchCnt(i);

        max_cnt = max(max_cnt, cnt);
        min_cnt = min(min_cnt, cnt);
    }

    cout << min_cnt << " " << max_cnt;

    return 0;
}