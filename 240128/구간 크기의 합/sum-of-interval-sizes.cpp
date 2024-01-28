#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    vector <pair<int,int>> points;

    cin >> n;
    
    for (int i = 0; i < n; i++) {
        int a,b;
        cin >> a >> b;
        points.push_back(make_pair(a, 1));
        points.push_back(make_pair(b, -1));
    }

    sort(points.begin(), points.end());

    int sum = 0;
    int ans = 0;
    int prev_point = points[0].first;
    for (int i = 0; i < points.size(); i++) {
        if (sum != 0) {
            ans += points[i].first - prev_point;
        }
        prev_point = points[i].first;
        sum += points[i].second;
    }

    cout << ans;


    return 0;
}