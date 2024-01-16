#include <iostream>
#include <queue>
#include <vector>
#include <functional>
using namespace std;

int main() {
    int n;
    priority_queue<int, vector<int>, greater<int>> pq;

    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        if (x == 0) {
            if (pq.empty()) {
                cout << "0\n";
            }
            else {
                cout << pq.top() << "\n";
                pq.pop();
            }
        }
        else {
            pq.push(x);
        }
    }
    return 0;
}