#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX_N 100005
#define INF 2e9

int N, M;
vector <pair<int,int>> edges[MAX_N];
int total_dist[MAX_N];

void Dijkstra(int start) {
    int dist[MAX_N];

    for (int i = 1; i <= N; i++) {
        dist[i] = INF;
    }

    dist[start] = 0;

    priority_queue<pair<int,int>> pq;

    pq.push(make_pair(-0, start));
    while(!pq.empty()) {
        int current_dist = -pq.top().first;
        int current_vertex = pq.top().second;
        pq.pop();

        if (dist[current_vertex] != current_dist)
            continue;

        for (int i = 0; i < edges[current_vertex].size(); i++) {
            int next_vertex = edges[current_vertex][i].first;
            int new_dist = current_dist + edges[current_vertex][i].second;

            if (dist[next_vertex] > new_dist) {
                dist[next_vertex] = new_dist;
                pq.push(make_pair(-new_dist, next_vertex));
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        total_dist[i] += dist[i];
    }

}

int main() {    
    int x, y;

    cin >> N >> M;
    cin >> x >> y;
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges[a].push_back(make_pair(b, c));
        edges[b].push_back(make_pair(a, c));
    }

    Dijkstra(x);
    Dijkstra(y);

    int ans = INF;
    for (int i = 1; i <= N; i++) {
        if (i == x || i == y)
            continue;

        ans = min(ans, total_dist[i]);
    }

    cout << ans + total_dist[x];

    return 0;
}