#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

#define MAX_N 205

int n, m;
long long x[MAX_N], y[MAX_N];
int uf[MAX_N];

void initialize() {
    for (int i = 1; i <= n; i++)
        uf[i] = i;
}

int find(int point) {
    if (point == uf[point])
        return point;
    
    return uf[point] = find(uf[point]);
}

void unionPoints(int point1, int point2) {
    int uf1 = find(point1);
    int uf2 = find(point2);

    uf[uf1] = uf2;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
    }

    initialize();

    vector <tuple<double,int,int>> edges;
    for (int i = 0; i < m; i++) {
        int point1, point2;
        cin >> point1 >> point2;
        unionPoints(point1, point2);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = i+1; j <= n; j++) {
            double distance = sqrt(
                (x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j])
            );
            edges.push_back({distance, i, j});
        }
    }

    sort(edges.begin(), edges.end());

    double ans = 0;
    for (auto e : edges) {
        int point1, point2;
        double distance;

        tie(distance, point1, point2) = e;
        if (find(point1) == find(point2))
            continue;
        
        unionPoints(point1, point2);
        ans += distance;
    }

    cout << fixed;
    cout.precision(2);

    cout << ans;

    return 0;
}