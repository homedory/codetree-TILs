#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;

vector <int> choosedIdx;
pair<int,int> point[20];
int n, m;
int ans = INT_MAX;


int maxDist() {
    int max_dist = 0;
    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < m; j++) {
            pair<int,int> p1 = point[choosedIdx[i]];
            pair<int,int> p2 = point[choosedIdx[j]];
            int dist = pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2);
            max_dist = max(max_dist, dist);
        }
    }

    return max_dist;
}

void choose(int idx, int cnt) {
    if (cnt == m) {
        ans = min(ans, maxDist());
        return;
    }

    if (idx == n)
        return;

    choosedIdx.push_back(idx);
    choose(idx + 1, cnt + 1);
    choosedIdx.pop_back();

    choose(idx + 1, cnt);
}

int main() {
    cin >> n >> m;
    
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        point[i] = make_pair(x,y);
    }

    choose(0, 0);

    cout << ans;


    return 0;
}