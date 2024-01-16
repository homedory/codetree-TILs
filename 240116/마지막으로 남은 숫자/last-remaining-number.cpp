#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n;
    priority_queue <int> pq;

    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        pq.push(x);
    }

    while(pq.size() >= 2) {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        if (a == b)
            continue;
        pq.push(a - b);
    }

    if (pq.empty()) {
        cout << "-1";
    }
    else {
        cout << pq.top();
    }

    return 0;
}