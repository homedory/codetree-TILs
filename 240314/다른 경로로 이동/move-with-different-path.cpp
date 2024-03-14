#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX_N 1005
#define INF 2e9

int dist[MAX_N];
vector <pair<int,int>> edges[MAX_N];
bool removed[MAX_N][MAX_N];
int n, m;

void Dijkstra(int start) {
    for (int i = 1; i <= n; i++) {
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

            if (removed[current_vertex][next_vertex])
                continue;
            
            if (dist[next_vertex] > new_dist) {
                dist[next_vertex] = new_dist;
                pq.push(make_pair(-new_dist, next_vertex));
            }
        }
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b, c;

        cin >> a >> b >> c;
        edges[a].push_back(make_pair(b, c));
        edges[b].push_back(make_pair(a, c));
    }


    Dijkstra(n);

    int x = 1;
    while(x != n) {
        for (int i = 0; i < edges[x].size(); i++) {
            int next_vertex = edges[x][i].first;
            int d = edges[x][i].second;

            if (dist[x] == dist[next_vertex] + d) {
                removed[x][next_vertex] = true;
                removed[next_vertex][x] = true;
                x = next_vertex;
                break;
            }
        }
    }

    Dijkstra(1);

    if (dist[n] == INF) {
        cout << -1;
    }
    else {
        cout << dist[n];
    }

    return 0;
}