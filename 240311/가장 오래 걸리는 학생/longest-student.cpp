#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX_N 100005
#define INF 2e9

int main() {
    int N, M;
    vector <pair<int,int>> edges[MAX_N];
    int dist[MAX_N];

    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int a, b, d;
        cin >> a >> b >> d;
        edges[a].push_back(make_pair(b, d));
        edges[b].push_back(make_pair(a, d));
    }

    for (int i = 1; i <= N; i++) {
        dist[i] = INF;
    }

    dist[N] = 0;

    priority_queue<pair<int,int>> pq;

    pq.push(make_pair(-0, N));

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

    int ans = 0;
    for (int i = 1; i < N; i++) {
        ans = max(ans, dist[i]);
    }

    cout << ans;

    return 0;
}