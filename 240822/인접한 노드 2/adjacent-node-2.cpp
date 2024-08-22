#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX_N 10005

int n;
int dp[MAX_N][2];
int num[MAX_N];
bool visited[MAX_N];
vector<int> edge[MAX_N];
vector<int> chosen_num;

void init() {
    for (int i = 1; i <= n; i++)
        visited[i] = false;
}

void traversal(int node) {
    visited[node] = true;

    for (auto child : edge[node]) {
        if (visited[child])
            continue;

        traversal(child);
        dp[node][1] += dp[child][0];
        dp[node][0] += max(dp[child][0], dp[child][1]);
    }
    dp[node][1] += num[node];
}

void find_chosen_num(int node, bool chosen) {
    visited[node] = true;
    
    if (chosen) {
        chosen_num.push_back(node);
    }

    for (auto child : edge[node]) {
        if (visited[child])
            continue;
        
        if (chosen)
            find_chosen_num(child, false);
        else
            find_chosen_num(child, (dp[child][1] > dp[child][0]));
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> num[i];
    
    for (int i = 0; i < n-1; i++) {
        int node1, node2;
        cin >> node1 >> node2;
        edge[node1].push_back(node2);
        edge[node2].push_back(node1);
    }

    traversal(1);
    init();
    find_chosen_num(1, (dp[1][1] > dp[1][0]));

    sort(chosen_num.begin(), chosen_num.end());
    int ans = max(dp[1][0], dp[1][1]);

    cout << ans << "\n";
    for (auto number : chosen_num)
        cout << number << " ";


    return 0;
}