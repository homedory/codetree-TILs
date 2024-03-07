#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 1e9

int main() {
    int n, m, k;
    vector <pair<int,int>> edges[20005];
    int dist[20005];
    bool visited[20005];

    cin >> n >> m;
    cin >> k;

    for (int i = 0; i < m; i++) {
        int x, y, cost;
        cin >> x >> y >> cost;
        edges[x].push_back(make_pair(y, cost));
        edges[y].push_back(make_pair(x, cost));
    }

    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
        visited[i] = false;
    }

    dist[k] = 0;

    priority_queue<pair<int,int>> pq;

    pq.push(make_pair(0, k));

    while(!pq.empty()) {
        int distance = -pq.top().first;
        int vertex = pq.top().second;
        pq.pop();

        if (visited[vertex])
            continue;

        visited[vertex] = true;
        dist[vertex] = distance;

        for (int i = 0; i < edges[vertex].size(); i++) {
            int next_vertex = edges[vertex][i].first;
            int cost = edges[vertex][i].second;

            if (dist[next_vertex] > distance + cost) {
                pq.push(make_pair(-(distance + cost), next_vertex));
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (dist[i] == INF) 
            cout << "-1\n";
        else
            cout << dist[i] << "\n";
    }   
    
    return 0;
}