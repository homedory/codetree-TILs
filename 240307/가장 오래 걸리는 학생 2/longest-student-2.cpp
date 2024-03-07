#include <iostream>
#include <queue>
using namespace std;

#define INF 1e9
#define MAX_N 100005

vector<pair<int,int>> edges[MAX_N];

int main() {
    int N, M;
    int dist[MAX_N];
    bool visited[MAX_N];

    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int start, end, d;
        cin >> start >> end >> d;
        edges[end].push_back(make_pair(start, d));
    }

    for (int i = 1; i <= N; i++) {
        dist[i] = INF;
        visited[i] = false;
    }

    dist[N] = 0;

    priority_queue<pair<int,int>> pq;

    pq.push(make_pair(0, N));

    int ans = 0;

    while(!pq.empty()) {
        int distance = -pq.top().first;
        int current_vertex = pq.top().second;
        pq.pop();

        if (visited[current_vertex])
            continue;

        visited[current_vertex] = true;
        dist[current_vertex] = distance;
        ans = distance;
        
        for (int i = 0; i < edges[current_vertex].size(); i++) {
            int next_vertex = edges[current_vertex][i].first;
            int cost = edges[current_vertex][i].second;

            if (dist[next_vertex] > distance + cost) {
                pq.push(make_pair(-(distance + cost), next_vertex));
            }
        }
    }

    cout << ans;

    return 0;
}