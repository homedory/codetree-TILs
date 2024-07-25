#include <iostream>
#include <vector>
using namespace std;

vector<int> edge[100005];
int n;
int max_dist_node;
int max_dist = 0;
bool visited[100005];

void init() {
    max_dist = 0;
    for (int i = 1; i <= n; i++) {
        visited[i] = false;
    }
}

void traversal(int curr_node, int dist_sum) {
    visited[curr_node] = true;

    if (dist_sum > max_dist) {
        max_dist = dist_sum;
        max_dist_node = curr_node;
    }

    for (int i = 0; i < edge[curr_node].size(); i++) {
        int next_node = edge[curr_node][i];

        if (visited[next_node])
            continue;

        traversal(next_node, dist_sum + 1);
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int node1, node2;
        cin >> node1 >> node2;
        edge[node1].push_back(node2);
        edge[node2].push_back(node1);
    }    

    init();
    traversal(1, 0);

    int start_node = max_dist_node;

    init();
    traversal(start_node, 0);
    int ans = (max_dist % 2 == 0) ? max_dist / 2 : max_dist / 2 + 1;

    cout << ans;

    return 0;
}