#include <iostream>
#include <queue>
using namespace std;

int main() {
    int N, cnt = 0;
    long long T;
    priority_queue<pair<long long, int>> pq; //<-end, index>

    cin >> N >> T;

    for (int i = 0; i < N; i++) {
        int start;
        long long v;
        cin >> start >> v;
        pq.push(make_pair(-((long long) start + v * T), i));
    }
    
    int idx = -1;

    while(!pq.empty()) {
        if (pq.top().second > idx) {
            idx = pq.top().second;
            cnt++;
        }
        pq.pop();
    }

    cout << cnt;

    return 0;
}