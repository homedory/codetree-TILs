#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;

#define MAX_N 1005

int arr[MAX_N][MAX_N], prefix_sum[MAX_N][MAX_N];

int main() {
    int N;
    vector <int> x, y;
    vector <pair<int,int>> points;
    unordered_set <int> x_set, y_set;
    unordered_map <int,int> nx, ny;

    cin >> N;
    for (int i = 0; i < N; i++) {
        int x_, y_;
        cin >> x_ >> y_;
        if (x_set.find(x_) == x_set.end()) {
            x.push_back(x_);
            x_set.insert(x_);
        }
        if (y_set.find(y_) == y_set.end()) {
            y.push_back(y_);
            y_set.insert(y_);
        }
        points.push_back(make_pair(x_, y_));
    }

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    for (int i = 0; i < x.size(); i++) {
        nx[x[i]] = i + 1;
    }

    for (int i = 0; i < y.size(); i++) {
        ny[y[i]] = i + 1;
    }


    for (int i = 0; i < points.size(); i++) {
        arr[nx[points[i].first]][ny[points[i].second]] = 1;
    }

    int x_len = x.size(), y_len = y.size();

    for (int i = 1; i <= x_len; i++) {
        for (int j = 1; j <= y_len; j++) {
            prefix_sum[i][j] = prefix_sum[i-1][j] + prefix_sum[i][j-1] - prefix_sum[i-1][j-1] + arr[i][j];
        }
    }

    int ans = MAX_N;

    for (int i = 1; i <= x_len; i++) {
        for (int j = 1; j <= y_len; j++) {
            int a = prefix_sum[i][j];
            int b = prefix_sum[x_len][j] - a;
            int c = prefix_sum[i][y_len] - a;
            int M = max(max(a, b), max(c, N - a - b - c));
            ans = min(ans, M);
        }
    }

    cout << ans;


    return 0;
}