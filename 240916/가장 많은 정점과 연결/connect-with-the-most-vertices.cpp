#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX_N 100005

int n, m, k;
int parent[MAX_N], min_cost[MAX_N];
bool connected[MAX_N];

void initialize() {
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }
}

int findRoot(int node) {
    if (parent[node] == node)
        return node;
    
    return parent[node] = findRoot(parent[node]);
}

void unionNodes(int node1, int node2) {
    int node1_root = findRoot(node1);
    int node2_root = findRoot(node2);
    
    min_cost[node2_root] = min(min_cost[node1_root], min_cost[node2_root]);
    parent[node1_root] = node2_root;
}

int main() {
    cin >> n >> m >> k;
    initialize();
    
    for (int i = 1; i <= n; i++) {
        cin >> min_cost[i];
    }

    for (int i = 0; i < m; i++) {
        int node1, node2;
        cin >> node1 >> node2;
        unionNodes(node1, node2);
    }

    vector <int> connecting_cost;
    for (int i = 1; i <= n; i++) {
        int root = findRoot(i);

        if (connected[root]) 
            continue;
        
        connecting_cost.push_back(min_cost[root]);
        connected[root] = true;
    }

    sort(connecting_cost.begin(), connecting_cost.end());

    int total_cost = 0;
    for (int i = 1; i < connecting_cost.size(); i++) {
        total_cost += connecting_cost[i];
        total_cost += connecting_cost[0];
    }

    if (total_cost > k)
        cout << "NO";
    else
        cout << total_cost;

    return 0;
}