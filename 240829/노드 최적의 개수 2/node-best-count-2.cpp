#include <iostream>
#include <vector>
using namespace std;

#define MAX_N 100005

int n, m;
vector <int> edge[MAX_N];
int dp[MAX_N][2];
bool node_selected[MAX_N];
bool visited[MAX_N];

void traversal(int cur_node) {
    visited[cur_node] = true;

    for (auto child : edge[cur_node]) {
        if (visited[child])
            continue;
        
        traversal(child);

        dp[cur_node][0] += dp[child][1];
        dp[cur_node][1] += min(dp[child][0], dp[child][1]);
    }

    if (!node_selected[cur_node])
        dp[cur_node][1] += 1;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n-1; i++) {
        int node1, node2;
        cin >> node1 >> node2;
        edge[node1].push_back(node2);
        edge[node2].push_back(node1);
    }

    for (int i = 0; i < m; i++) {
        int node;
        cin >> node;
        node_selected[node] = true;
    }

    traversal(1);

    int ans = min(dp[1][0], dp[1][1]);

    cout << ans;

    
    return 0;
}