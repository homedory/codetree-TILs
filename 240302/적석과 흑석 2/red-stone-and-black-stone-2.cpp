#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;


int main() {
    int C, N;
    vector<int> red;
    vector<pair<int,int>> black;

    cin >> C >> N;

    for (int i = 0; i < C; i++) {
        int T;
        cin >> T;
        red.push_back(T);
    }

    for (int i = 0; i < N; i++) {
        int A, B;
        cin >> A >> B;
        black.push_back(make_pair(A, B));
    }

    sort(red.begin(), red.end());
    sort(black.begin(), black.end());

    int ans = 0;
    int j = 0;
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < C; i++) {
        int x = red[i];

        while(j < N && black[j].first <= red[i]) {
            pq.push(black[i].second);
            j++;
        }

        if (pq.top() >= red[i]) {
            pq.pop();
            ans++;
        }
        else {
            while(!pq.empty()) {
                pq.pop();
            }
        }
    }

    cout << ans;

    return 0;
}