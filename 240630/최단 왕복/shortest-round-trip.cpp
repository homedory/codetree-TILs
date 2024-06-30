#include <iostream>
using namespace std;

#define INF 1000000000

int dist[105][105];

int main() {
    int n, m;

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dist[i][j] = INF;
        }
        dist[i][i] = 0;
    }

    for (int i = 0; i < m; i++) {
        int start, end, cost;
        cin >> start >> end >> cost;
        dist[start][end] = min(dist[start][end], cost);
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    int min_dist = 2 * INF;

    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            min_dist = min(min_dist, dist[i][j] + dist[j][i]);
        }
    }

    cout << min_dist;

    return 0;
}