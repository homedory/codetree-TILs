#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    vector <int> v;
    
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }

    v.push_back(0);

    sort(v.begin(), v.end());

    int s = 0;
    int ans = 0;

    for (int e = n; e > s; e--) {
        while(s + 1 < e && v[s + 1] + v[e] <= k) {
            s++;
        }
        ans += s;
    }

    cout << ans;


    return 0;
}