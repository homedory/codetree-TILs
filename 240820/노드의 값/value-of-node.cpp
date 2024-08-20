#include <iostream>
#include <vector>
using namespace std;

#define MAX_N 10005

int n;
vector <int> edge[MAX_N];
int number[MAX_N], redundance[MAX_N];
bool visited[MAX_N];
int ans = 0;

void traversal(int node) {
    visited[node] = true;

    int sum = 0;
    for (auto child : edge[node]) {
        if (visited[child])
            continue;
        
        traversal(child);
        sum += redundance[child];
        ans += abs(redundance[child]);
    }

    redundance[node] = sum + (number[node] - 1);
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

    cout << ans;

    return 0;
}