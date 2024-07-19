#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector <pair<int,int>> edge[1005];

int getDistance(int vertex1, int vertex2) {
    queue<pair<int,int>> q;
    bool visited[1005];
    for (int i = 0; i < 1005; i++)
        visited[i] = false;
    
    q.push(make_pair(vertex1, 0));
    visited[vertex1] = true;
    while(!q.empty()) {
        int curr_vertex = q.front().first;
        int curr_dist = q.front().second;
        q.pop();

        if (curr_vertex == vertex2)
            return curr_dist;

        for (int i = 0; i < edge[curr_vertex].size(); i++) {
            int next = edge[curr_vertex][i].first;
            int dist = curr_dist + edge[curr_vertex][i].second;

            if (visited[next])
                continue;

            visited[next] = true;
            q.push(make_pair(next, dist));
        }
    }

    return 0;
}

int main() {
    int n, m;
    
    cin >> n >> m;
    for (int i = 0; i < n - 1; i++) {
        int vertex1, vertex2, distance;
        cin >> vertex1 >> vertex2 >> distance;
        edge[vertex1].push_back(make_pair(vertex2, distance));
        edge[vertex2].push_back(make_pair(vertex1, distance));
    }

    for (int i = 0; i < m; i++) {
        int vertex1, vertex2;
        cin >> vertex1 >> vertex2;
        cout << getDistance(vertex1, vertex2) << "\n";
    }

    return 0;
}