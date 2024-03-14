#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX_N 1005
#define INF 2e9

int n, m;
int dist[MAX_N];
int prev_vertex[MAX_N];

vector <pair<int,int>> edges[MAX_N];

int Dijkstra(int remove_s, int remove_e) {
    for (int i = 0; i <= n; i++) {
        dist[i] = INF;
    }

    dist[1] = 0;

    priority_queue<pair<int,int>> pq;

    pq.push(make_pair(-0, 1));
    while(!pq.empty()) {
        int current_dist = -pq.top().first;
        int current_vertex = pq.top().second;
        pq.pop();

        if (dist[current_vertex] != current_dist)
            continue;
        
        for (int i = 0; i < edges[current_vertex].size(); i++) {
            int next_vertex = edges[current_vertex][i].first;
            int new_dist = current_dist + edges[current_vertex][i].second;

            if (current_vertex == remove_s && next_vertex == remove_e)
                continue;
            
            if (dist[next_vertex] > new_dist) {
                dist[next_vertex] = new_dist;
                prev_vertex[next_vertex] = current_vertex;
                pq.push(make_pair(-new_dist, next_vertex));
            }
        }

    }

    return dist[n];
}

int main() {
    vector <int> path;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges[a].push_back(make_pair(b, c));
        edges[b].push_back(make_pair(a, c));
    }

    int shortest_dist = Dijkstra(0, 0);

    int x = n;
    while(x != 1) {
        path.push_back(x);
        x = prev_vertex[x];
    }
    path.push_back(1);

    int ans = 0;

    for (int i = path.size() - 1; i > 0; i--) {
        int start = path[i];
        int end = path[i - 1];

        int d = Dijkstra(start, end);
        if (d != shortest_dist)
            ans++;
    }

    cout << ans;

    return 0;
}