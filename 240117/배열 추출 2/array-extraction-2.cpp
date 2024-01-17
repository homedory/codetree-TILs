#include <iostream>
#include <queue>
#include <vector>
#include <functional>
using namespace std;

int main() {
    int n, x;
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x == 0) {
            if (pq.size() > 0) {
                cout << pq.top().second << "\n";
                pq.pop();
            }
            else {
                cout << "0\n";
            }
        }
        else {
            pq.push(make_pair(abs(x), x));
        }
    }
    return 0;
}