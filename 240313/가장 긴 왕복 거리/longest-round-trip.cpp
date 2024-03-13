#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define MAX_N 1005
#define INF 1e9

int main() {
    int n, m, x;
    vector <pair<int,int>> edges[MAX_N];
    vector <pair<int,int>> rev_edges[MAX_N];
    int dist[MAX_N], rev_dist[MAX_N];
    
    cin >> n >> m >> x;

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges[a].push_back(make_pair(b, c));
        rev_edges[b].push_back(make_pair(a, c));
    }

    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
        rev_dist[i] = INF;
    }

    priority_queue<pair<int,int>> pq;

    dist[x] = 0;
    pq.push(make_pair(-0, x));
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

    rev_dist[x] = 0;
    pq.push(make_pair(-0, x));
    while(!pq.empty()) {
        int current_dist = -pq.top().first;
        int current_vertex = pq.top().second;
        pq.pop();

        if (rev_dist[current_vertex] != current_dist) 
            continue;
        
        for (int i = 0; i < rev_edges[current_vertex].size(); i++) {
            int next_vertex = rev_edges[current_vertex][i].first;
            int new_dist = current_dist + rev_edges[current_vertex][i].second;

            if (rev_dist[next_vertex] > new_dist) {
                rev_dist[next_vertex] = new_dist;
                pq.push(make_pair(-new_dist, next_vertex));
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, dist[i] + rev_dist[i]);
    }
    
    cout << ans;

    return 0;
}