#include <iostream>
#include <climits>
using namespace std;

int n;
int cost[11][11];
bool visited[11];
int start = 1;
int ans = INT_MAX;


void move(int vertex, int totalCost, int vertexCnt) {
    if (vertexCnt == n) {
        if (cost[vertex][start] != 0) {
            totalCost += cost[vertex][start];
            ans = min(ans, totalCost);
        }
        visited[vertex] = false;
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (cost[vertex][i] == 0 || visited[i])
            continue;    
        
        visited[i] = true;
        move(i, totalCost + cost[vertex][i], vertexCnt + 1);
    }

    visited[vertex] = false;
}


int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> cost[i][j];
        }
    }

    visited[1] = true;
    move(1, 0, 1);   

    cout << ans;

    return 0;
}