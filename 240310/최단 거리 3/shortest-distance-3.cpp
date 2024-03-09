#include <iostream>
using namespace std;

#define MAX_N 1005
#define INF 2e9

int edge[MAX_N][MAX_N];
bool visited[MAX_N];

int main() {
    int n, m;
    int A, B;
    int dist[MAX_N];

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (edge[a][b] == 0) {
            edge[a][b] = c;
            edge[b][a] = c;
        }
        else {
            edge[a][b] = min(edge[a][b], c);
            edge[b][a] = min(edge[b][a], c);
        }
    }

    cin >> A >> B;

    for (int i = 0; i <= n; i++) {
        dist[i] = INF;
    }

    dist[A] = 0;

    for (int i = 1; i <= n; i++) {
        int min_idx = 0;
        for (int j = 1; j <= n; j++) {
            if (visited[j])
                continue;

            if (dist[j] < dist[min_idx]) {
                min_idx = j;
            }
        }

        visited[min_idx] = true;

        for (int j = 1; j <= n; j++) {
            if (edge[min_idx][j] == 0)
                continue;
            
            if (dist[j] > dist[min_idx] + edge[min_idx][j])
                dist[j] = dist[min_idx] + edge[min_idx][j];
        }
    }

    cout << dist[B];

    return 0;
}