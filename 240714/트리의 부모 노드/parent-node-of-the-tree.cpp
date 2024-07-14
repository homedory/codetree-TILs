#include <iostream>
#include <vector>
using namespace std;

int n;
vector <int> edge[100005];
bool visited[100005];
int parent[100005];

void traverse(int vertex) {
    visited[vertex] = true;
    for (int i = 0; i < edge[vertex].size(); i++) {
        int next_vertex = edge[vertex][i];

        if (visited[next_vertex])
            continue;
        
        parent[next_vertex] = vertex;
        traverse(next_vertex);
    }    
}

int main() {
    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        int vertex1, vertex2;
        cin >> vertex1 >> vertex2;
        edge[vertex1].push_back(vertex2);
        edge[vertex2].push_back(vertex1);
    }    

    traverse(1);

    for (int i = 2; i <= n; i++) {
        cout << parent[i] << "\n";
    }
    
    return 0;
}