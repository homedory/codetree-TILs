#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX_N 1005
#define INF 2e9

int dist[MAX_N];

int main() {
    int n, m;
    int A, B;
    vector <pair<int,int>> edges[MAX_N];

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int start, end, cost;
        cin >> start >> end >> cost;
        edges[start].push_back(make_pair(end, cost));
        edges[end].push_back(make_pair(start, cost));
    }

    cin >> A >> B;

    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
    }

    dist[B] = 0;

    priority_queue<pair<int,int>> pq;

    pq.push(make_pair(0, B));

    while(!pq.empty()) {
        int current_dist = -pq.top().first;
        int current_vertex = pq.top().second;
        pq.pop();

        if (dist[current_vertex] != current_dist) {
            continue;
        }

        for (int i = 0; i < edges[current_vertex].size(); i++) {
            int next_vertex = edges[current_vertex][i].first;
            int new_dist = current_dist + edges[current_vertex][i].second;

            if (dist[next_vertex] > new_dist) {
                dist[next_vertex] = new_dist;
                pq.push(make_pair(-new_dist, next_vertex));
            }
        }
    }

    int ans = dist[A];

    cout << ans << "\n";

    int x = A;
    int sum = 0;
    while(x != B) {

        for (int i = 0; i < edges[x].size(); i++) {
            int next_vertex = edges[x][i].first;
            int d = edges[x][i].second;

            if (sum + d + dist[next_vertex] == ans) {
                cout << x << " ";
                x = next_vertex;
                sum += d;
                break;
            }
        }
    }
    cout << B;

    
    
    return 0;
}