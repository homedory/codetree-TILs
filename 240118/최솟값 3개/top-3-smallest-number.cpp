#include <iostream>
#include <queue>
#include <vector>
#include <functional>
using namespace std;

int main() {
    int n;
    priority_queue <int, vector<int>, greater<int>> pq;
    
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        pq.push(x);
        if (pq.size() < 3) {
            cout << "-1\n";
        }
        else {
            int a = pq.top(); pq.pop();
            int b = pq.top(); pq.pop();
            int c = pq.top(); pq.pop();

            long long mult = (long long) a * b * c;
            cout << mult <<"\n";

            pq.push(a);
            pq.push(b);
            pq.push(c);
        }
    }
    return 0;
}