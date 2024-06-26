#include <iostream>
using namespace std;

#define INF 1000000000

int n, m;
int dist[105][105];

void initDist() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dist[i][j] = INF;
        }
        dist[i][i] = 0;
    }
}

int main() {
    cin >> n >> m;
    
    initDist();

    for (int i = 0; i < m; i++) {
        int start, end, distance;
        cin >> start >> end >> distance;
        dist[start][end] = min(dist[start][end], distance);
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dist[i][j] == INF) 
                cout << -1 << " ";
            else
                cout << dist[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}