#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector <int> edge[505];
bool visited[505];
int node_cnt, edge_cnt;

void init() {
    for (int i = 1; i <= n; i++) {
        visited[i] = false;
    }
}

void traversal(int node) {
    visited[node] = true;

    node_cnt++;

    for (int i = 0; i < edge[node].size(); i++) {
        int next_node = edge[node][i];
        edge_cnt++;

        if (visited[next_node])
            continue;

        traversal(next_node);
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int node1, node2;
        cin >> node1 >> node2;
        edge[node1].push_back(node2);
        edge[node2].push_back(node1);
    }

    init();

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (visited[i])
            continue;

        node_cnt = 0;
        edge_cnt = 0;
        traversal(i);

        if (edge_cnt == 2 * (node_cnt-1))
            ans++;    
    }

    cout << ans;


    return 0;
}