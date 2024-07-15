#include <iostream>
#include <vector>
using namespace std;

int n;
int parent[55];
vector <int> edges[55];
int root_node, deleted_node;
int leaf_node_cnt = 0;

void traversal(int node) {
    if (node == deleted_node)
        return;
    int child_cnt = 0;
    for (int i = 0; i < edges[node].size(); i++) {
        int next_node = edges[node][i];
        if (next_node == deleted_node)
            continue;
        
        traversal(next_node);
        child_cnt++;
    }

    if (child_cnt == 0)
        leaf_node_cnt++;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int parent;
        cin >> parent;
        if (parent == -1)
            root_node = i;
        else 
            edges[parent].push_back(i);
    }
    
    cin >> deleted_node;

    traversal(root_node);

    cout << leaf_node_cnt;


    return 0;
}