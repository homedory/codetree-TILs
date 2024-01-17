#include <iostream>
#include <queue>
#include <vector>
#include <functional>
using namespace std;

int main() {
    int T;
    cin >> T;
    while(T--) {
        int n, mid;
        priority_queue<int> below;
        priority_queue<int, vector<int>, greater<int>> above;
        cin >> n >> mid;
        cout << mid << " ";
        for (int i = 2; i <= n; i++) {
            int x;
            cin >> x;
            if (x >= mid) {
                above.push(x);
            }
            else {
                below.push(x);
            }
            if (i % 2 == 1) {
                if (above.size() > below.size()) {
                    below.push(mid);
                    mid = above.top();
                    above.pop();
                }
                else if (above.size() < below.size()) {
                    above.push(mid);
                    mid = below.top();
                    below.pop();
                }
                cout << mid << " "; 
            }
        }
        cout << "\n";
    }
    return 0;
}