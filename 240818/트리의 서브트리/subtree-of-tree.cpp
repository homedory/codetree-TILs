#include <iostream>
#include <vector>
using namespace std;

vector<int> edge[100005];
int subtree_node_cnt[100005];
bool visited[100005];

void traversal(int node) {
    visited[node] = true;

    subtree_node_cnt[node] = 1;
    for (auto next_node : edge[node]) {
        if (visited[next_node])
            continue;
        
        traversal(next_node);
        subtree_node_cnt[node] += subtree_node_cnt[next_node];
    }
}

int main() {
    int n, r, q;
    cin >> n >> r >> q;

    for (int i = 0; i < n-1; i++) {
        int node1, node2;
        cin >> node1 >> node2;
        edge[node1].push_back(node2);
        edge[node2].push_back(node1);
    }

    traversal(r);
    
    for (int i = 0; i < q; i++) {
        int u;
        cin >> u;
        cout << subtree_node_cnt[u] << "\n";
    }


    return 0;
}