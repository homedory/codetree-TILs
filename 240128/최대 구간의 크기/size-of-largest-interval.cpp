#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    vector <pair<int,int>> points;

    cin >> n;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        points.push_back(make_pair(a, 1));
        points.push_back(make_pair(b, -1));
    }

    sort(points.begin(), points.end());

    int sum = 0, ans = 0;
    int start_point;
    for (int i = 0; i < points.size(); i++) {
        if (points[i].second == 1) {
            if (sum == 0) {
                start_point = points[i].first;
            }
            sum += points[i].second;
        }
        else if (points[i].second == -1) {
            sum += points[i].second;
            if (sum == 0) {
                ans = max(ans, points[i].first - start_point);
            }
        }   
    }

    cout << ans;
    return 0;
}