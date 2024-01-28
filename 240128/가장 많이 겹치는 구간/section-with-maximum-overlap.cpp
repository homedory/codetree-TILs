#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    vector <pair<int,int>> v;

    cin >> n;

    for (int i = 0; i < n; i++) {
        int x1, x2;
        cin >> x1 >> x2;
        v.push_back(make_pair(x1, 1));
        v.push_back(make_pair(x2, -1));
    }

    sort(v.begin(), v.end());

    int sum = 0, ans = 0;

    for (int i = 0; i < v.size(); i++) {
        sum += v[i].second;
        ans = max(ans, sum);
    }

    cout << ans;


    return 0;
}