#include <iostream>
using namespace std;

int dist[105][105];

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> dist[i][j]; 
        }
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        cout << dist[a][b] << "\n";
    }
    return 0;
}