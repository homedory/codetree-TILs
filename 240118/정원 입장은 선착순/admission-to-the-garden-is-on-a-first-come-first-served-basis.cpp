#include <iostream>
#include <queue>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;

int main() {
    int n, ans = 0;
    int A[100005], T[100005];
    vector <pair<int, int>> v; //<a,i>
    priority_queue<int, vector<int>, greater<int>> pq;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> A[i] >> T[i];
        v.push_back(make_pair(A[i], i));
    }

    sort(v.begin(), v.end());

    int idx = 1;

    int now = v[0].first;

    pq.push(v[0].second);

    while(!pq.empty()) {
        ans = max(ans, now - A[pq.top()]);

        now += T[pq.top()];
        pq.pop();

        while(idx < n) {
            int arrive = v[idx].first;
            int num = v[idx].second;
            if (arrive > now) {
                break;
            }
            pq.push(num);
            idx++;
        }

        if (idx < n && pq.empty()) {
            now = v[idx].first;
            pq.push(v[idx].second);
            idx++;
        }
    }

    cout << ans;


    return 0;
}