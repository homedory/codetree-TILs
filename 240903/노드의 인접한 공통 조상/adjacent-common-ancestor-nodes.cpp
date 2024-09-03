#include <iostream>
#include <vector>
using namespace std;

#define MAX_N 10005

int n;
vector <int> child[MAX_N];
int depth[MAX_N];
int parent[MAX_N];

int findRootNode() {
    for (int i = 1; i <= n; i++) {
        if (parent[i] == 0)
            return i;
    }
    return 1;
}

void calcDepth(int cur_node) {
    for (auto child_node : child[cur_node]) {
        depth[child_node] = depth[cur_node] + 1;
        calcDepth(child_node);
    }
}

int findLCA(int node1, int node2) {
    while(depth[node1] != depth[node2]) {
        if (depth[node1] > depth[node2])
            node1 = parent[node1];
        else
            node2 = parent[node2];
    }

    while(node1 != node2) {
        node1 = parent[node1];
        node2 = parent[node2];
    }

    return node1;
}

int main() {
    cin >> n;

    for (int i = 0; i < n-1; i++) {
        int parent_node, child_node;
        cin >> parent_node >> child_node;
        child[parent_node].push_back(child_node);
        parent[child_node] = parent_node;
    }
    
    int node1, node2;
    cin >> node1 >> node2;

    int root_node = findRootNode();
    depth[root_node] = 1;
    
    calcDepth(root_node);
    
    int ans = findLCA(node1, node2);

    cout << ans;


    return 0;
}