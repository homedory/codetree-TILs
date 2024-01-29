#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    vector <pair<int,int>> p;

    cin >> n;

    for (int i = 0; i < n; i++) {
        int s, e;
        cin >> s >> e;
        p.push_back(make_pair(s, -1));
        p.push_back(make_pair(e, 1));
    }

    sort(p.begin(), p.end());

    int ans = 0;
    int sum = 0;
    for (int i = 0; i < p.size(); i++) {
        int v = p[i].second;
        sum += v;
        ans = max(ans, -sum);
    }

    cout << ans;
    return 0;
}