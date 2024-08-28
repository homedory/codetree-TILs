#include <iostream>
#include <vector>
using namespace std;

#define MAX_N 100005

int n, k;
int num[MAX_N];
vector <int> edge[MAX_N];
int dp[MAX_N][12][2];
bool visited[MAX_N];

void traversal(int cur_node) {
    visited[cur_node] = true;

    dp[cur_node][1][1] = num[cur_node];
    for (auto child : edge[cur_node]) {
        if (visited[child])
            continue;
        
        traversal(child);
        
        for (int i = k; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                dp[cur_node][i][0] = max(dp[cur_node][i][0], max(dp[child][j][0], dp[child][j][1]) + dp[cur_node][i-j][0]);
                if (i == 0)
                    continue;
                dp[cur_node][i][1] = max(dp[cur_node][i][1], dp[child][j][0] + dp[cur_node][i-j][1]);
            }
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

    for (int i = 1; i <= n; i++) {
        cin >> num[i];
    }

    cin >> k;

    traversal(1);

    int ans = 0;
    for (int i = 0; i <= k; i++) {
        ans = max(ans, dp[1][i][0]);
        ans = max(ans, dp[1][i][1]);
    }

    cout << ans;

    return 0;
}