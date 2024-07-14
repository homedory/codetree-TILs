#include <iostream>
#include <vector>
using namespace std;

vector <pair<int,int>> edges[100005];
int n;
bool visited[100005];
int max_len, max_point;

void initialize() {
    for (int i = 1; i <= n; i++) {
        visited[i] = false;
    }
    max_len = 0;
}

void traverse(int vertex, int total_len) {
    if (total_len > max_len) {
        max_len = total_len;
        max_point = vertex;
    }

    for (int i = 0; i < edges[vertex].size(); i++) {
        int next_vertex = edges[vertex][i].first;
        int len = edges[vertex][i].second;

        if (visited[next_vertex])
            continue;

        visited[next_vertex] = true;
        traverse(next_vertex, total_len + len);
    }
}

int main() {
    
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int vertex1, vertex2, len;
        cin >> vertex1 >> vertex2 >> len;
        edges[vertex1].push_back(make_pair(vertex2, len));
        edges[vertex2].push_back(make_pair(vertex1, len));
    }

    initialize();
    visited[1] = true;
    traverse(1, 0);
    int root = max_point;

    initialize();
    visited[root] = true;
    traverse(root, 0);
    int diameter = max_len;

    cout << diameter;

    return 0;
}