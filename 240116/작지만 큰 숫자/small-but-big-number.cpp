#include <iostream>
#include <set>
using namespace std;

int main() {
    int n, m;
    set <int> s;

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        s.insert(x);
    }

    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        set<int>::iterator it = s.upper_bound(x);
        if (it == s.begin()) {
            cout << "-1\n";
        }
        else {
            it--;
            cout << *it << "\n";
            s.erase(*it);
        }
    }
    return 0;
}