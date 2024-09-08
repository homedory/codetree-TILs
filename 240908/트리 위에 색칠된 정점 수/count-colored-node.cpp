#include <iostream>
#include <vector>
using namespace std;

#define MAX_N 100005
#define MAX_H 18

int n, k, q;
int depth[MAX_N], node_cnt[MAX_N];
int parent[MAX_H][MAX_N];
vector <int> edge[MAX_N];
bool selected[MAX_N];
bool visited[MAX_N];

void traversal(int cur_node) {
    visited[cur_node] = true;

    for (auto child : edge[cur_node]) {
        if (visited[child])
            continue;
        
        depth[child] = depth[cur_node] + 1;
        parent[0][child] = cur_node;
        node_cnt[child] = node_cnt[cur_node] + ((selected[child]) ? 1 : 0);
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

    for (int h = MAX_H-1; h >= 0; h--) {
        if (depth[parent[h][low_node]] >= depth[high_node])
            low_node = parent[h][low_node];
    }

    if (low_node == high_node)
        return low_node;
    
    for (int h = MAX_H-1; h >= 0; h--) {
        if (parent[h][low_node] == parent[h][high_node])
            continue;
        
        low_node = parent[h][low_node];
        high_node = parent[h][high_node];
    }

    return parent[0][low_node];
}

int countNode(int node1, int node2) {
    int lca = findLCA(node1, node2);
    int count = node_cnt[node1] + node_cnt[node2] - 2*node_cnt[lca] + ((selected[lca]) ? 1 : 0);

    return count;
}

int main() {
    cin >> n;
    for (int i = 0; i < n-1; i++) {
        int node1, node2;
        cin >> node1 >> node2;
        edge[node1].push_back(node2);
        edge[node2].push_back(node1);
    }

    cin >> k;
    for (int i = 0; i < k; i++) {
        int num;
        cin >> num;
        selected[num] = true;
    }

    depth[1] = 1;
    node_cnt[1] = ((selected[1]) ? 1 : 0);
    traversal(1);
    calcParseTable();

    cin >> q;
    for (int i = 0; i < q; i++) {
        int node1, node2;
        cin >> node1 >> node2;

        int ans = countNode(node1, node2);

        cout << ans << "\n";
    }


    return 0;
}