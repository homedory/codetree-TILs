#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX_N 100005
#define INF 2e9

int main() {
    int n, m, a, b, c;
    vector <pair<int,int>> edges[MAX_N];
    int dist[3][MAX_N];

    cin >> n >> m;
    cin >> a >> b >> c;
    for (int i = 0; i < m; i++) {
        int s, e, d;
        cin >> s >> e >> d;
        edges[s].push_back(make_pair(e, d));
        edges[e].push_back(make_pair(s, d));
    }

    for (int i = 0; i <= n; i++) {
        dist[0][i] = dist[1][i] = dist[2][i] = INF;
    }

    int start[3] = {a, b, c};

    for (int i = 0; i < 3; i++) {
        int start_vertex = start[i];

        dist[i][start_vertex] = 0;

        priority_queue<pair<int,int>> pq;

        pq.push(make_pair(-0, start_vertex));

        while(!pq.empty()) {
            int current_dist = -pq.top().first;
            int current_vertex = pq.top().second;
            pq.pop();

            if (dist[i][current_vertex] != current_dist)
                continue;

            for (int j = 0; j < edges[current_vertex].size(); j++) {
                int next_vertex = edges[current_vertex][j].first;
                int new_dist = current_dist + edges[current_vertex][j].second;

                if (dist[i][next_vertex] > new_dist) {
                    dist[i][next_vertex] = new_dist;
                    pq.push(make_pair(-new_dist, next_vertex));
                }
            }
            
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (i == a || i == b || i == c)
            continue;

        int min_dist = min(dist[0][i], min(dist[1][i], dist[2][i]));
        ans = max(ans, min_dist);
    }

    cout << ans;

    return 0;
}