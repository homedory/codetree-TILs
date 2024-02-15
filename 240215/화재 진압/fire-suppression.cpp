#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define MAX_N 100005

int main() {
    int n, m;
    int fire[MAX_N], fire_station[MAX_N], L[MAX_N], R[MAX_N];
    vector<pair<int,int>> pos;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> fire[n];
        pos.push_back({fire[n], 0});
    }

    for (int i = 0; i < m; i++) {
        cin >> fire_station[i];
        pos.push_back({fire_station[i], 1});
    }

    pos.push_back({-2000000000, 1});

    sort(pos.begin(), pos.end());

    L[0] = -2000000000;
    for (int i = 1; i < pos.size(); i++) {
        if (pos[i].second == 1) {
            L[i] = pos[i].first;
        }
        else {
            L[i] = L[i - 1];
        }
    }

    R[pos.size()] = 2000000000;
    for (int i = pos.size() - 1; i >= 1; i--) {
        if (pos[i].second == 1) {
            R[i] = pos[i].first;
        }
        else {
            R[i] = R[i + 1];
        }
    }

    int ans = 0;

    for (int i = 1; i < pos.size(); i++) {
        if (pos[i].second == 0) {
            int d = min(pos[i].first - L[i], R[i] - pos[i].first);
            ans = max(ans, d);
        }
    }

    cout << ans;

    return 0;
}