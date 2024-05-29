#include <iostream>
#include <vector>
using namespace std;

int n;
int row_visited[10];
int grid[10][10];
int ans = 0;

void choose(int cur_column, int cur_sum) {
    if (cur_column == n) {
        ans = max(ans, cur_sum);
        return;
    }

    for (int i = 0; i < n; i++) {
        if (row_visited[i])
            continue;
        
        row_visited[i] = 1;
        choose(cur_column + 1, cur_sum + grid[i][cur_column]);
        row_visited[i] = 0;
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    choose(0, 0);

    cout << ans;

    return 0;
}