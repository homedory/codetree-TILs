#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define MAX_N 1005
#define INF 2e9

int main() {
    int n, m, A, B;
    vector <pair<int,int>> edges[MAX_N];
    int path[MAX_N];
    int dist[MAX_N];
    
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int x, y, c;
        cin >> x >> y >> c;
        edges[x].push_back(make_pair(y, c));
        edges[y].push_back(make_pair(x, c));
    }

    cin >> A >> B;

    for (int i = 1; i <= m; i++) {
        dist[i] = INF;
        path[i] = i;
    }

    dist[A] = 0;

    priority_queue<pair<int,int>> pq;

    pq.push(make_pair(-0, A));

    while(!pq.empty()) {
        int current_dist = -pq.top().first;
        int current_vertex = pq.top().second;
        pq.pop();

        if (dist[current_vertex] != current_dist)
            continue;
        
        for (int i = 0; i < edges[current_vertex].size(); i++) {
            int next_vertex = edges[current_vertex][i].first;
            int new_dist = edges[current_vertex][i].second + current_dist;

            if (new_dist < dist[next_vertex]) {
                dist[next_vertex] = new_dist;
                path[next_vertex] = current_vertex;
                pq.push(make_pair(-new_dist, next_vertex));
            }
        }
    }

    vector <int> ans;
    int idx = B;

    ans.push_back(idx);
    while(path[idx] != A) {
        idx = path[idx];
        ans.push_back(idx);
    }
    ans.push_back(A);

    cout << dist[B] << "\n";
    for (int i = ans.size() - 1; i >= 0; i--) {
        cout << ans[i] << " ";
    }
    

    return 0;
}