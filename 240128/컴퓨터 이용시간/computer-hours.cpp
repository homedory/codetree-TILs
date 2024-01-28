#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

#define MAX_N 100005

int main() {
    int n;
    vector <tuple<int,int,int>> points;
    int used[MAX_N];

    cin >> n;

    for (int i = 1; i <= n; i++) {
        int p, q;
        cin >> p >> q;
        points.push_back(make_tuple(p, 1, i));
        points.push_back(make_tuple(q, -1, i));
    }

    sort(points.begin(), points.end());

    int sum = 0;
    priority_queue <int, vector<int>, greater<int>> pq;
    for (int i = 0; i < points.size(); i++) {
        int x, v, n;
        tie(x, v, n) = points[i];

        sum += v;
        if (v == 1) {
            if (pq.empty()) {
                used[n] = sum;
            }
            else {
                used[n] = pq.top();
                pq.pop();
            }
        }
        else if (v == -1) {
            pq.push(used[n]);
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << used[i] << " ";
    }
    return 0;
}