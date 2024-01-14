#include <iostream>
#include <set>
using namespace std;

int main() {
    int n, m;
    set<pair<int,int>> consec, len;

    cin >> n >> m;

    consec.insert(make_pair(0, n));  //<start,end>
    len.insert(make_pair(n + 1, 0)); //<len,start>

    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;

        set<pair<int,int>>::iterator it = consec.upper_bound(make_pair(x,n));
        it--;
        int s = it->first, e = it->second;
        consec.erase(make_pair(s, e));
        len.erase(*len.find(make_pair(e - s + 1, s)));

        if (x > s) {
            consec.insert(make_pair(s, x - 1));
            len.insert(make_pair(x - s, s));
        }
        if (x < e) {
            consec.insert(make_pair(x + 1, e));
            len.insert(make_pair(e - x, x + 1));
        }
        
        cout << len.rbegin()->first << "\n";
    }
    return 0;
}