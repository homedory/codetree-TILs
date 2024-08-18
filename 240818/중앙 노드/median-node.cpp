#include <iostream>
#include <vector>
using namespace std;

vector<int> edge[100005];
bool visited[100005];
int node_cnt[100005];
int n, root_node, central_node;

void init() {
    for (int i = 1; i <= n; i++) {
        visited[i] = false;
        node_cnt[i] = 1;
    }
}

void find_central(int node) {
    visited[node] = true;
    central_node = node;

    if (edge[node].size() > 2) 
        return;

    for (auto next_node : edge[node]) {
        if (visited[next_node])
            continue;
        find_central(next_node);    
    }
}

void count_subtree_node(int node) {
    visited[node] = true;

    for (auto child_node : edge[node]) {
        if (visited[child_node])
            continue;
        
        count_subtree_node(child_node);
        node_cnt[node] += node_cnt[child_node];
    }
}

int main() {
    
    cin >> n >> root_node;

    for (int i = 0; i < n-1; i++) {
        int node1, node2;
        cin >> node1 >> node2;
        edge[node1].push_back(node2);
        edge[node2].push_back(node1);
    }

    if (edge[root_node].size() < 2)
        find_central(root_node);
    else
        central_node = root_node;

    init();

    count_subtree_node(central_node);

    int max_cnt = 0;
    int min_cnt = n;
    for (auto child_node : edge[central_node]) {
        max_cnt = max(max_cnt, node_cnt[child_node]);
        min_cnt = min(min_cnt, node_cnt[child_node]);
    }

    cout << max_cnt - min_cnt;

    return 0;
}