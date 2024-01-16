#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n, m;
    priority_queue<int> pq;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        pq.push(x);
    }

    for (int i = 0; i < m; i++) {
        int x = pq.top();
        pq.pop();
        pq.push(x - 1);
    }

    cout << pq.top() << "\n";
    return 0;
}