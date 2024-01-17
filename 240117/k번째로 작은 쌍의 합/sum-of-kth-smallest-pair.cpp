#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m, k;
    vector <int> A, B;
    priority_queue<tuple<int,int,int>> pq; //<sum, A[i], B[i]>

    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        A.push_back(x);
    }

    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        B.push_back(x);
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    for (int i = 0; i < m; i++) {
        pq.push(make_tuple(-(A[0] + B[i]), 0, i));
    }

    for (int i = 1; i < k; i++) {
        int x, y;
        tie(ignore, x, y) = pq.top();
        pq.pop();
        
        x++;
        if (x < n) {
            pq.push(make_tuple(-(A[x] + B[y]), x, y));
        }
    }

    int ans;
    tie(ans, ignore, ignore) = pq.top();
    cout << -ans;
    return 0;
}