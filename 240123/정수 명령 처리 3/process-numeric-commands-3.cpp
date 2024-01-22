#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main() {
    int N;
    deque <int> dq;
    cin >> N;

    for (int i = 0; i < N; i++) {
        string str;
        int A;

        cin >> str;
        if (str == "push_front") {
            cin >> A;
            dq.push_front(A);
        }
        else if (str == "push_back") {
            cin >> A;
            dq.push_back(A);
        }
        else if (str == "pop_front") {
            cout << dq.front() << "\n";
            dq.pop_front();
        }
        else if (str == "pop_back") {
            cout << dq.back() << "\n";
            dq.pop_back();
        }
        else if (str == "size") {
            cout << dq.size() << "\n";
        }
        else if (str == "empty") {
            if (dq.empty()) {
                cout << "1\n";
            }
            else {
                cout << "0\n";
            }
        }
        else if (str == "front") {
            cout << dq.front() << "\n";
        }
        else if (str == "back") {
            cout << dq.back() << "\n";
        }
    }
    return 0;
}