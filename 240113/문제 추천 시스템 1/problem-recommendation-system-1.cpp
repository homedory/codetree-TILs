#include <iostream>
#include <set>
#include <string>
using namespace std;

int main() {
    int n, m, P, L;
    set <pair<int,int>> problem;

    cin >> n;
    for (int i = 0; i < n; i++) {
        int p, l;
        cin >> p >> l;
        problem.insert(make_pair(l, p));
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        string str;
        cin >> str;
        if (str == "rc") {
            int x;
            cin >> x;
            if (x == 1) {
                cout << problem.rbegin()->second << "\n";
            }
            else {
                cout << problem.begin()->second << "\n";
            }
        } 
        else if (str == "ad") {
            int p, l;
            cin >> p >> l;
            problem.insert(make_pair(l, p));
        }
        else if (str == "sv") {
            int p, l;
            cin >> p >> l;
            problem.erase(make_pair(l, p));
        }
    }
    return 0;
}