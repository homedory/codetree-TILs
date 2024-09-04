#include <iostream>
#include <vector>
using namespace std;

#define MAX_N 10005
#define MAX_H 15
int n;
int parent[MAX_H+1][MAX_N];
vector <int> edge[MAX_N];
int depth[MAX_N];
bool visited[MAX_N];

void calcParent(int cur_node) {
    visited[cur_node] = true;

    for (auto child: edge[cur_node]) {
        if (visited[child])
            continue;
        
        parent[0][child] = cur_node;
        depth[child] = depth[cur_node] + 1;
        calcParent(child);
    }
}

void calcParseTable() {
    for (int h = 1; h <= MAX_H; h++) {
        for (int i = 1; i <= n; i++) {
            parent[h][i] = parent[h-1][parent[h-1][i]];
        }
    }
}


int findLCA(int node1, int node2) {    
    int low_node = (depth[node1] > depth[node2]) ? node1 : node2;
    int high_node = (depth[node1] <= depth[node2]) ? node1 : node2;

    for (int h = MAX_H; h >= 0; h--) {
        if (depth[low_node] - depth[high_node] >= (1 << h)) {
            low_node = parent[h][low_node];
        }
    }

    if (low_node == high_node)
        return low_node;

    for (int h = MAX_H; h >= 0; h--) {
        if (parent[h][low_node] == parent[h][high_node])
            continue;
        
        low_node = parent[h][low_node];
        high_node = parent[h][high_node];
    }

    return parent[0][low_node];
}

int main() {
    int q;

    cin >> n;    
    for (int i = 0; i < n-1; i++) {
        int node1, node2;
        cin >> node1 >> node2;
        edge[node1].push_back(node2);
        edge[node2].push_back(node1);
    }

    depth[1] = 1;
    calcParent(1);
    calcParseTable();

    cin >> q;
    for (int i = 0; i < q; i++) {
        int node1, node2;
        cin >> node1 >> node2;
        
        int ans = findLCA(node1, node2);
        cout << ans << "\n";
    }

    return 0;
}