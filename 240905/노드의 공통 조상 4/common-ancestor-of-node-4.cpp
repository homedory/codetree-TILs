#include <iostream>
#include <vector>
using namespace std;

#define MAX_N 100005

int n;
vector <int> edge[MAX_N];
int depth[MAX_N];
int parent[MAX_N];
bool visited[MAX_N];

void calcParent(int cur_node) {
    visited[cur_node] = true;

    for (auto child : edge[cur_node]) {
        if (visited[child])
            continue;
        
        parent[child] = cur_node;
        depth[child] = depth[cur_node] + 1;
        calcParent(child);
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
        int node1, node2;
        cin >> node1 >> node2;
        edge[node1].push_back(node2);
        edge[node2].push_back(node1);
    }

    calcParent(1);

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int node1, node2;
        cin >> node1 >> node2;
        
        int ans = findLCA(node1, node2);
        cout << ans << "\n";
    }
    
    return 0;
}