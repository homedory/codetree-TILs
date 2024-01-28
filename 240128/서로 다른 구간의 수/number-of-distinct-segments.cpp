#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    vector <pair<int,int>> v;

    cin >> n;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back(make_pair(a,1));
        v.push_back(make_pair(b, -1));
    }
    
    sort(v.begin(), v.end());

    int sum = 0, ans = 0;
    for (int i = 0; i < v.size(); i++) {
        sum += v[i].second;
        if (sum == 0) {
            ans++;
        }
    }

    cout << ans;

    
    return 0;
}