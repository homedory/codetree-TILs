#include <iostream>
#include <set>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

int main() {
    int n;
    vector <tuple<int,int,int>> points;

    cin >> n;

    for (int i = 0; i < n; i++) {
        int x1, x2, y;
        cin >> y >> x1 >> x2;
        points.push_back(make_tuple(x1, y, 1));
        points.push_back(make_tuple(x2, y, -1));
    }

    sort(points.begin(), points.end());

    set <int> s;

    int front_y = -2000000000;
    int ans = 0;

    for (int i = 0; i < points.size(); i++) {
        int x, y, v;
        tie(x, y, v) = points[i];
        if (v == 1) {
            s.insert(y);
        }
        else if (v == -1) {
            s.erase(y);
        }

        if (s.size() > 0 && *s.begin() != front_y) {
            ans++;
            front_y = *s.begin();
        }
    }

    cout << ans;


    return 0;
}