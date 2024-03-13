#include <iostream>
#include <vector>
using namespace std;

#define MAX_N 255
#define INF 2e9

int edge[MAX_N][MAX_N];
int dist[MAX_N];
int N, M;

int Dijkstra() {
    bool visited[MAX_N];

    for (int i = 0; i <= N; i++) {
        dist[i] = INF;
        visited[i] = false;
    }

    dist[1] = 0;

    for (int i = 1; i <= N; i++) {
        int min_idx = 0;
        for (int j = 1; j <= N; j++) {
            if (visited[j])
                continue;

            if (dist[min_idx] > dist[j])
                min_idx = j;
        }

        visited[min_idx] = true;

        for (int j = 1; j <= N; j++) {
            if (edge[min_idx][j] == 0)
                continue;
            
            if (dist[j] > dist[min_idx] + edge[min_idx][j]) {
                dist[j] = dist[min_idx] + edge[min_idx][j];
            }
        }
    }

    return dist[N];
}

int main() {  
    vector <pair<int,int>> edges;

    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int a, b, d;
        cin >> a >> b >> d;

        edge[a][b] = d;
        edge[b][a] = d;
        edges.push_back(make_pair(a, b));
    }

    int shortes_dist = Dijkstra();

    int max_dist = 0;
    for (int i = 0; i < edges.size(); i++) {
        int a = edges[i].first;
        int b = edges[i].second;

        edge[a][b] *= 2;
        edge[b][a] *= 2;

        max_dist = max(max_dist, Dijkstra());

        edge[a][b] /= 2;
        edge[b][a] /= 2;
    }

    cout << max_dist - shortes_dist;

    return 0;
}