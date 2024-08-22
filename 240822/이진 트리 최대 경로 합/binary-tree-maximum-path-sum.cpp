#include <iostream>
#include <vector>
#include <climits>
using namespace std;

#define MAX_N 30005

int N;
int number[MAX_N]; 
int dp[MAX_N];
int ans = INT_MIN;
vector<int> edge[MAX_N];
bool visited[MAX_N];

void traversal(int node) {
    visited[node] = true;

    int sum = number[node];
    for (auto child : edge[node]) {
        if (visited[child])
            continue;
        
        traversal(child);
        sum += dp[child];
        dp[node] = max(dp[node], dp[child]);
    }
    dp[node] += number[node];
    ans = max(ans, sum);
    ans = max(ans, dp[node]);
}

int main() {
    cin >> N;
    for (int i = 0; i < N-1; i++) {
        int node1, node2;
        cin >> node1 >> node2;
        edge[node1].push_back(node2);
        edge[node2].push_back(node1);
    }

    for (int i = 1; i <= N; i++) {
        cin >> number[i];
    }
    
    traversal(1);

    cout << ans;


    return 0;
}