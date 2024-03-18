#include <iostream>
#include <vector>
using namespace std;

#define MAX_N 1005

int visit_cnt = 0;
vector <int> graph[MAX_N];
bool visited[MAX_N];

void dfs(int vertex) {
    for (int i = 0; i < graph[vertex].size(); i++) {
        int next_vertex = graph[vertex][i];
        if (visited[next_vertex])
            continue;
        
        visited[next_vertex] = true;
        visit_cnt++;
        dfs(next_vertex);
    }
}

int main() {
    int N, M;

    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int vertex1, vertex2;

        cin >> vertex1 >> vertex2;
        graph[vertex1].push_back(vertex2);
        graph[vertex2].push_back(vertex1);
    }

    visited[1] = true;
    dfs(1);

    cout << visit_cnt;

    return 0;
}