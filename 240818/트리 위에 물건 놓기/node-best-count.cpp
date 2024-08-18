#include <iostream>
#include <vector>
using namespace std;

vector <int> edge[100005];
int dp[100005][2];
int n;
bool visited[10005];

void traversal(int node) {
    visited[node] = true;

    dp[node][1] = 1;
    for (int i = 0; i < edge[node].size(); i++) {
        int next_node = edge[node][i];
        if (visited[next_node])
            continue;
        
        traversal(next_node);
        dp[node][0] += dp[next_node][1];
        dp[node][1] += min(dp[next_node][0], dp[next_node][1]);
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

    traversal(1);

    cout << min(dp[1][0], dp[1][1]);


    return 0;
}