#include <iostream>
#include <set>
using namespace std;

int main() {
    int n, m;
    set <pair<int,int>> p;

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        p.insert(make_pair(x,y));
    }

    for (int i = 0; i < m; i++) {
        int k;
        cin >> k;
        set <pair<int,int>>::iterator it = p.lower_bound(make_pair(k,-1000000000));
        if (it == p.end()) {
            cout << "-1 -1\n";
            continue;
        }
        cout << it->first << " " << it->second << "\n";
        p.erase(make_pair(it->first, it->second));
    }

    return 0;
}