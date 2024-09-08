#include <iostream>
#include <vector>
using namespace std;

#define MAX_N 100005
#define MAX_H 18

int n, q;
vector <pair<int, int>> edge[MAX_N];
int depth[MAX_N], dist[MAX_N];
int parent[MAX_H][MAX_N];
bool visited[MAX_N];

void traversal(int cur_node) {
    visited[cur_node] = true;

    for (auto e : edge[cur_node]) {
        int child = e.first;
        int weight = e.second;

        if (visited[child])
            continue;
        
        depth[child] = depth[cur_node] + 1;
        parent[0][child] = cur_node;
        dist[child] = dist[cur_node] + weight;
        traversal(child);
    }
}

void calcParseTable() {
    for (int h = 1; h < MAX_H; h++) {
        for (int i = 1; i <= n; i++) {
            parent[h][i] = parent[h-1][parent[h-1][i]];
        }
    }
}

int findLCA(int node1, int node2) {
    int low_node = (depth[node1] > depth[node2]) ? node1 : node2;
    int high_node = (depth[node1] <= depth[node2]) ? node1 : node2;

    for (int h = MAX_H - 1; h >= 0; h--) {
        if (depth[parent[h][low_node]] >= depth[high_node])
            low_node = parent[h][low_node];
    }

    if (low_node == high_node)
        return low_node;

    for (int h = MAX_H - 1; h >= 0; h--) {
        if (parent[h][low_node] == parent[h][high_node])
            continue;

        low_node = parent[h][low_node];
        high_node = parent[h][high_node];
    }

    return parent[0][low_node];
}

int calcDist(int node1, int node2) {
    int lca = findLCA(node1, node2);

    return (dist[node1] - dist[lca]) + (dist[node2] - dist[lca]);
}

int main() {
    cin >> n;
    for (int i = 0; i < n-1; i++) {
        int node1, node2, weight;
        cin >> node1 >> node2 >> weight;
        edge[node1].push_back(make_pair(node2, weight));
        edge[node2].push_back(make_pair(node1, weight));
    }

    depth[1] = 1;
    traversal(1);
    calcParseTable();

    cin >> q;
    for (int i = 0; i < q; i++) {
        int node1, node2;
        cin >> node1 >> node2;
        
        int ans = calcDist(node1, node2);
        cout << ans << "\n";
    }


    return 0;
}