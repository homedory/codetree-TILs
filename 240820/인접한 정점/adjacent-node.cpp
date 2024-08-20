#include <iostream>
#include <vector>
#include <climits>
using namespace std;

#define MAX_N 10005

int n;
int dp[MAX_N][2];
int number[MAX_N];
vector <int> edge[MAX_N];
bool visited[MAX_N];

void traversal(int cur_node) {
    visited[cur_node] = true;

    bool child_chosen = false;
    int sum_not_select = 0;
    int sum_select = 0;
    int min_diff = INT_MAX;

    for (auto child : edge[cur_node]) {
        if (visited[child])
            continue;
        
        traversal(child);

        if (dp[child][0] <= dp[child][1])
            child_chosen = true;
        
        min_diff = min(min_diff, abs(dp[child][0] - dp[child][1]));
        sum_not_select += max(dp[child][0], dp[child][1]);
        sum_select += dp[child][0];
    }

    if (!child_chosen && min_diff != INT_MAX)
        sum_not_select -= min_diff;
    
    dp[cur_node][0] = sum_not_select;
    dp[cur_node][1] = sum_select + number[cur_node];
}


int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> number[i];
    
    for (int i = 0; i < n-1; i++) {
        int node1, node2;
        cin >> node1 >> node2;
        edge[node1].push_back(node2);
        edge[node2].push_back(node1);
    }

    traversal(1);

    int ans = max(dp[1][0], dp[1][1]);

    cout << ans;

    return 0;
}