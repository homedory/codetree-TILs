#include <iostream>
#include <vector>
using namespace std;

int dist_cnt = 0;
vector <int> edge[100005];

bool visited[100005];

void traversal(int node, int dist) {
    visited[node] = true;

    int leaf_cnt = 0;
    for (int i = 0; i < edge[node].size(); i++) {
        int next_node = edge[node][i];
        if (visited[next_node])
            continue;
        
        leaf_cnt++;
        traversal(next_node, dist + 1);
    }

    if (leaf_cnt == 0)
        dist_cnt += dist;
}

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        int node1, node2;
        cin >> node1 >> node2;
    }

    for (int i = 1; i <= N; i++) {
        visited[i] = false;
    }

    traversal(1, 0);

    cout << (dist_cnt % 2 == 0) ? 0 : 1;

    return 0;
}