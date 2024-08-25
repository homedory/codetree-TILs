#include <iostream>
#include <vector>
using namespace std;

#define MAX_N 100005

int n;
int dp[MAX_N][2][2];
vector<int> edge[MAX_N];
bool visited[MAX_N];

void traversal(int cur_node) {
    visited[cur_node] = true;

    int min_diff = (int)1e9;
    bool selelcted = false;
    bool leaf_node = true;
    for (auto child : edge[cur_node]) {
        if (visited[child])
            continue;
        
        leaf_node = false;

        traversal(child);

        dp[cur_node][0][0] += dp[child][1][0];
        dp[cur_node][1][0] += min(dp[child][1][0], dp[child][1][1]);
        if (dp[child][1][0] >= dp[child][1][1])
            selelcted = true;
        min_diff = min(min_diff, abs(min(dp[child][1][0], dp[child][1][1]) - dp[child][1][1]));
        dp[cur_node][1][1] += min(dp[child][0][0], min(dp[child][1][0], dp[child][1][1]));
    }
    dp[cur_node][1][1] += 1;

    if (selelcted)
        return;
    
    dp[cur_node][1][0] += min_diff;

    if (leaf_node)
        dp[cur_node][1][0] = (int)1e9;
}
int main() {
    cin >> n;
    for (int i = 0; i < n-1; i++) {
        int node1, node2;
        cin >> node1 >> node2;
        edge[node1].push_back(node2);
        edge[node2].push_back(node1);
    }

    traversal(1);

    int ans = min(dp[1][1][0], dp[1][1][1]);

    cout << ans;


    return 0;
}