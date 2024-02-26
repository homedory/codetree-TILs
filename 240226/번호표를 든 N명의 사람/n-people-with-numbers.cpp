#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define MAX_N 10005

int N, T;
int arr[MAX_N];

bool IsPossible(int k) {
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < k; i++) {
        pq.push(arr[i]);
    }

    for (int i = k; i < N; i++) {
        int x = pq.top();
        pq.pop();
        pq.push(x + arr[i]);
    }

    int end;
    while(!pq.empty()) {
        end = pq.top();
        pq.pop();
    }

    return end <= T;
}

int main() {
    cin >> N >> T;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int l = 1, r = 2 * MAX_N;
    int ans = MAX_N;

    while(l <= r) {
        int mid = (l + r) / 2;

        if (IsPossible(mid)) {
            r = mid - 1;
            ans = min(ans, mid);
        }
        else {
            l = mid + 1;
        }
    }

    cout << ans;


    return 0;
}