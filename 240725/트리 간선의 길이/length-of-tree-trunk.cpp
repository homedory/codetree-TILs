#include <iostream>
#include <vector>
using namespace std;

int n;
vector <pair<int,int>> edge[10005];
int max_weight_sum = 0;
int max_weight_node;
bool visited[10005];

void init() {
    max_weight_sum = 0;
    for (int i = 1; i <= n; i++) {
        visited[i] = false;
    }
}

void traversal(int node, int weight_sum) {
    visited[node] = true;

    if (weight_sum > max_weight_sum) {
        max_weight_sum = weight_sum;
        max_weight_node = node;
    }

    for (int i = 0; i < edge[node].size(); i++) {
        int next_node = edge[node][i].first;
        int weight = edge[node][i].second;

        if (visited[next_node])
            continue;
        
        traversal(next_node, weight_sum + weight);
    }
}

int main() {
    

    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int node1, node2, weight;
        cin >> node1 >> node2 >> weight;
        edge[node1].push_back(make_pair(node2, weight));
        edge[node2].push_back(make_pair(node1, weight));
    }

    init();
    traversal(1, 0);

    int start_node = max_weight_node;

    init();
    traversal(start_node, 0);
    
    cout << max_weight_sum;
    
    return 0;
}