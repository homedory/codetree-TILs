#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

struct compare {
    bool operator()(pair<int,int> a, pair<int,int> b) {
        if (abs(a.first) + abs(a.second) == abs(b.first) + abs(b.second)) {
            if (a.first == b.first) {
                return a.second > b.second;
            }
            return a.first > b.first;
        }
        return abs(a.first) + abs(a.second) > abs(b.first) + abs(b.second);
    }
};

int main() {
    int n, m;
    priority_queue<pair<int,int>, vector<pair<int,int>>, compare> pq;

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        pq.push(make_pair(x,y));
    }

    for (int i = 0; i < m; i++) {
        int x = pq.top().first + 2;
        int y = pq.top().second + 2;
        pq.pop();
        pq.push(make_pair(x,y));
    }

    cout << pq.top().first << " " << pq.top().second; 
    return 0;
}