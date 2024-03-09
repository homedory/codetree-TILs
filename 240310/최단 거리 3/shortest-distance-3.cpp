#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX_N 1005
#define INF 2e9

int main() {
    int n, m;
    int A, B;
    vector <pair<int,int>> edges[MAX_N];
    int dist[MAX_N];

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges[a].push_back(make_pair(b, c));
        edges[b].push_back(make_pair(a, c));
    }

    cin >> A >> B;

    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
    }

    dist[A] = 0;

    priority_queue<pair<int,int>> pq;

    pq.push(make_pair(0, A));

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

    cout << dist[B];

    return 0;
}