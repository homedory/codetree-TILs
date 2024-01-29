#include <iostream>
#include <map>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

#define MAX_N 50005

int check[MAX_N];

int main() {
    int n;
    vector <tuple<int,int,int,int>> points;

    cin >> n;

    for (int i = 1; i <= n; i++) {
        int x1, x2, y;
        cin >> y >> x1 >> x2;
        points.push_back(make_tuple(x1, y, i, 1));
        points.push_back(make_tuple(x2, y, i, -1));
    }

    sort(points.begin(), points.end());

    map <int, int> m;

    int front_y = -2000000000;
    int ans = 0;

    for (int i = 0; i < points.size(); i++) {
        int x, y, v, idx;
        tie(x, y, idx, v) = points[i];
        if (v == 1) {
            m[y] = idx;
        }
        else if (v == -1) {
            m.erase(y);
        }

        if (m.size() > 0 && m.begin()->first != front_y) {
            if (!check[m.begin()->second]) {
                ans++;
                check[m.begin()->second] = 1;
            }
            front_y = m.begin()->first;
        }
    }

    cout << ans;


    return 0;
}