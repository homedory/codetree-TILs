#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <unordered_set>
using namespace std;

#define MAX_N 100005

int length[MAX_N];

int main() {
    int n;

    cin >> n;
    vector <tuple<int,int,int>> points;

    for (int i = 1; i <= n; i++) {
        int a, b;
        cin >> a >> b;
        points.push_back(make_tuple(min(a,b), i, 1));
        points.push_back(make_tuple(max(a,b), i, -1));
    }

    sort(points.begin(), points.end());

    unordered_set <int> s;
    int prev_x;
    int total_len = 0;

    // tie(prev_x, ignore, ignore) = points[0];

    for (int i = 0; i < points.size(); i++) {
        int x, idx, v;
        tie(x, idx, v) = points[i];
        
        //if it was single line just before this point
        if (s.size() == 1) {
            length[*s.begin()] += x - prev_x;
        }

        //calculate total length
        if (s.size() > 0) {
            total_len += x - prev_x;
        }
        prev_x = x;


        if (v == 1) {
            s.insert(idx);
        }
        else if (v == -1) {
            s.erase(idx);
        }

    }

    int min_num = 1000000000;
    for (int i = 1; i <= n; i++) {
        min_num = min(min_num, length[i]);
    }

    cout << total_len - min_num;


    return 0;
}