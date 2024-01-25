#include <iostream>
#include <set>
#include <unordered_map>
using namespace std;

#define MAX_N 1005

int arr[MAX_N][MAX_N], prefix_sum[MAX_N][MAX_N];

int main() {
    int n ,q;
    set <int> x_set, y_set;
    unordered_map <int,int> x_mapper, y_mapper;
    pair<int,int> points[MAX_N];

    cin >> n >> q;

    for (int i = 0; i < n; i++) {
        int x,y;
        cin >> x >> y;
        x_set.insert(x);
        y_set.insert(y);
        points[i].first = x;
        points[i].second = y;
    }

    int cnt = 1;
    for (set<int>::iterator it = x_set.begin(); it != x_set.end(); it++) {
        x_mapper[*it] = cnt;
        cnt++;
    }

    cnt = 1;
    for (set<int>::iterator it = y_set.begin(); it != y_set.end(); it++) {
        y_mapper[*it] = cnt;
        cnt++;
    }

    int x_size = x_set.size();
    int y_size = y_set.size();

    for (int i = 0; i < n; i++) {
        int new_x = x_mapper[points[i].first];
        int new_y = y_mapper[points[i].second];
        arr[new_x][new_y] = 1;
    }

    for (int i = 1; i<= x_size; i++) {
        for (int j = 1; j <= y_size; j++) {
            prefix_sum[i][j] = prefix_sum[i-1][j] + prefix_sum[i][j-1] - prefix_sum[i-1][j-1] + arr[i][j];
        }
    }

    for (int i = 0; i < q; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        if (x_set.lower_bound(x1) == x_set.upper_bound(x2) || y_set.lower_bound(y1) == y_set.upper_bound(y2)) {
            cout << "0\n";
            continue;
        }

        int nx1 = x_mapper[*x_set.lower_bound(x1)];
        int ny1 = y_mapper[*y_set.lower_bound(y1)];

        int nx2 = x_mapper[*(--x_set.upper_bound(x2))];
        int ny2 = y_mapper[*(--y_set.upper_bound(y2))];

        cout << prefix_sum[nx2][ny2] - prefix_sum[nx1-1][ny2] - prefix_sum[nx2][ny1-1] + prefix_sum[nx1-1][ny1-1] << "\n";
    }

    
    return 0;
}