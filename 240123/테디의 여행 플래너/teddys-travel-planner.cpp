#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main() {
    int N, Q;
    string str;
    deque <string> dq;

    cin >> N >> Q;
    
    for (int i = 0; i < N; i++) {
        cin >> str;
        dq.push_back(str);
    }

    for (int i = 0; i < Q; i++) {
        int x;
        cin >> x;

        if (x == 1) {
            if (dq.size() > 1) {
                dq.push_back(dq.front());
                dq.pop_front();
            }
        }
        else if (x == 2) {
            if (dq.size() > 1) {
                dq.push_front(dq.back());
                dq.pop_back();
            }
        }
        else if (x == 3) {
            if (dq.size() > 1) {
                string temp = dq.front();
                dq.pop_front();
                dq.pop_front();
                dq.push_front(temp);
            }
        }
        else if (x == 4) {
            cin >> str;
            
            string temp = dq.front();
            dq.pop_front();
            dq.push_front(str);
            dq.push_front(temp);
        }

        if (dq.size() > 2) {
            string temp = dq.front();
            dq.pop_front();
            cout << dq.back() << " " << dq.front() << "\n";
            dq.push_front(temp);
        }
        else {
            cout << "-1\n";
        }
    }

   
}