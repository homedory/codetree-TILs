#include <iostream>
#include <vector>
using namespace std;

#define MAX_N 100005

int n, s, d;
vector<int> edge[MAX_N];
bool visited[MAX_N];
int dp[MAX_N];

int traversal(int node) {
    visited[node] = true;

    int child_cnt = 0;
    int max_leaf_dist = 0;
    int dist_sum = 0;
    for (auto child : edge[node]) {
        if (visited[child])
            continue;
        
        child_cnt++;
        max_leaf_dist = max(max_leaf_dist, traversal(child));
        dist_sum += dp[child];
    }

    if (max_leaf_dist >= d)
        dp[node] = dist_sum + 2;

    if (child_cnt == 0) 
        return 1;
    else
        return max_leaf_dist + 1;
}

int main() {
    cin >> n >> s >> d;

    for (int i = 0; i < n-1; i++) {
        int node1, node2;
        cin >> node1 >> node2;
        edge[node1].push_back(node2);
        edge[node2].push_back(node1);
    }

    traversal(s);

    int ans = dp[s] - 2;

    cout << ans;


    return 0;
}