#include <iostream>
#include <vector>
using namespace std;

#define MAX_N 100005

int n, k;
vector<int> edge[MAX_N];
int num[MAX_N];
int dp[MAX_N][2][12];
bool visited[MAX_N];

void traversal(int cur_node) {
    visited[cur_node] = true;

    vector<int> child;
    for (auto next_node : edge[cur_node]) {
        if (visited[next_node])
            continue;
        
        traversal(next_node);
        child.push_back(next_node);
    }

    // leaf node case
    if (edge[cur_node].size() <= 1) {
        dp[cur_node][1][1] = num[cur_node];
        return;
    }

    for (int i = 0; i <= k; i++) { 
        for (int j = 0; j+i <= k; j++) {
            dp[cur_node][1][i+j+1] = max(dp[cur_node][1][i+j+1], num[cur_node] + dp[child[0]][0][i] + dp[child[1]][0][j]);

            int max_child_0 = max(dp[child[0]][0][i], dp[child[0]][1][i]);
            int max_child_1 = max(dp[child[1]][0][j], dp[child[1]][1][j]);
            dp[cur_node][0][i+j] = max(dp[cur_node][0][i+j], max_child_0 + max_child_1);
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n-1; i++) {
        int node1, node2;
        cin >> node1 >> node2;
        edge[node1].push_back(node2);
        edge[node2].push_back(node1);
    }

    for (int i = 1; i <= n; i++)
        cin >> num[i];

    cin >> k;

    traversal(1);

    int ans = 0;
    for (int i = 0; i <= k; i++) {
        ans = max(ans, dp[1][0][i]);
        ans = max(ans, dp[1][1][i]);
    }

    cout << ans;


    return 0;
}