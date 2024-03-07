#include <iostream>
using namespace std;

#define INF 1000000000

int edge[105][105];
int dist[105];
int visited[105];

int main() {
    int n, m;

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int start, end, cost;
        cin >> start >> end >> cost;
        edge[start][end] = cost;
    }

    for (int i = 0; i <= n; i++) {
        dist[i] = INF;
    }

    dist[1] = 0;

    for (int i = 0; i < n; i++) {
        int min_idx = 0;
        for (int j = 1; j <= n; j++) {
            if (visited[j] == 0 && dist[j] < dist[min_idx]) {
                min_idx = j;
            }
        }

        visited[min_idx] = 1;

        for (int j = 1; j <= n; j++) {
            if (edge[min_idx][j] == 0)
                continue;

            if (dist[j] > dist[min_idx] + edge[min_idx][j]) {
                dist[j] = dist[min_idx] + edge[min_idx][j];
            }
        }
    }

    for (int i = 2; i <= n; i++) {
        if (dist[i] == INF) {
            cout << "-1\n";
        }
        else {
            cout << dist[i] << "\n";
        }
    }

    return 0;
}