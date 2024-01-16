#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
    int N;
    priority_queue<int> pq;

    cin >> N;

    for (int i = 0; i < N; i++) {
        string str;
        int x;

        cin >> str;
        if (str == "push") {
            cin >> x;
            pq.push(x);
        }
        else if (str == "pop") {
            cout << pq.top() << "\n";
            pq.pop();
        }
        else if (str == "size") {
            cout << pq.size() << "\n";
        }
        else if (str == "empty") {
            cout << pq.empty() << "\n";
        }
        else if (str == "top") {
            cout << pq.top() << "\n";
        }
    }
    return 0;
}