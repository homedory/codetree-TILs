#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define MAX_N 1005
#define INF 2e9

int dist[MAX_N];
int edge[MAX_N][MAX_N];
bool visited[MAX_N];

int main() {
    int n, m;
    int A, B;
    
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int start, end, cost;
        cin >> start >> end >> cost;
        edge[start][end] = cost;
        edge[end][start] = cost;
    }

    cin >> A >> B;

    for (int i = 0; i <= n; i++) {
        dist[i] = INF;
    }

    dist[B] = 0;

    for (int i = 1; i <= n; i++) {
        int min_idx = 0;
        for (int j = 0; j <= n; j++) {
            if (visited[j])
                continue;

            if (dist[min_idx] > dist[j]) {
                min_idx = j;
            }
        }

        visited[min_idx] = true;

        for (int j = 1; j <= n; j++) {
            if (edge[min_idx][j] == 0)
                continue;

            if (dist[j] > edge[min_idx][j] + dist[min_idx]) {
                dist[j] = edge[min_idx][j] + dist[min_idx];
            }
        }
    }

    cout << dist[A] << "\n";

    int x = A;
    cout << x << " ";
    
    while(x != B) {
        for (int i = 1; i <= n; i++) {
            if (edge[i][x] == 0)
                continue;

            if (dist[x] == edge[i][x] + dist[i]) {
                x = i;
                break;
            }
        }
        cout << x << " ";
    }
    

    return 0;
}