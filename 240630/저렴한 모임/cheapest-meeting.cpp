#include <iostream>
using namespace std;

#define INF 100000000

int dist[105][105];
int n, m;

int main() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dist[i][j] = INF;
        }
        dist[i][i] = 0;
    }

    int v1, v2, e;
    cin >> v1 >> v2 >> e;

    for (int i = 0; i < m; i++) {
        int start, end, cost;
        cin >> start >> end >> cost;
        dist[start][end] = cost;
        dist[end][start] = cost;
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    int min_cost = INF;

    for (int k = 1; k <= n; k++) {
        int cost = dist[v1][k] + dist[v2][k] + dist[k][e];
        min_cost = min(min_cost, cost);
    }

    if (min_cost == INF)
        cout << -1;
    else
        cout << min_cost;

    return 0;
}