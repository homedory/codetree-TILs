#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX_TOTAL 100000

int n, m;
int uf[MAX_TOTAL];

void initialize() {
    for (int i = 1; i <= n*m; i++) 
        uf[i] = i;
}

int find(int node) {
    if (node == uf[node])
        return node;
    
    return uf[node] = find(uf[node]);
}

void unionNodes(int node1, int node2) {
    int node1_uf = find(node1);
    int node2_uf = find(node2);

    uf[node1_uf] = node2_uf;
}

int main() {
    cin >> n >> m;

    vector <tuple<int,int,int>> edges;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= m-1; j++) {
            int weight;
            cin >> weight;
            edges.push_back({weight, i*m+j, i*m+j+1});
        }
    }

    for (int i = 0; i < n-1; i++) {
        for (int j = 1; j <= m; j++) {
            int weight;
            cin >> weight;
            edges.push_back({weight, i*m+j, (i+1)*m+j});
        }
    }

    sort(edges.begin(), edges.end());
    initialize();

    int weight_sum = 0;
    for (auto e : edges) {
        int node1, node2, weight;
        tie(weight, node1, node2) = e;

        if (find(node1) == find(node2))
            continue;
        
        unionNodes(node1, node2);
        weight_sum += weight;
    }

    cout << weight_sum;

    return 0;
}