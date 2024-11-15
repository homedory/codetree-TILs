#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX_N 505

int n;
int grid[MAX_N][MAX_N], dp[MAX_N][MAX_N];
vector <tuple<int,int,int>> numbers;

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

bool inRange(int row, int col) {
    return row > 0 && row <= n && col > 0 && col <= n;
}

void calculateDP(int row, int col) {
    for (int dir = 0; dir < 4; dir++) {
        int next_row = row + dr[dir];
        int next_col = col + dc[dir];

        if (!inRange(next_row, next_col))
            continue;
        
        if (grid[row][col] <= grid[next_row][next_col])
            continue;
        
        dp[row][col] = max(dp[row][col], dp[next_row][next_col] + 1);
    }
}

void initialize() {
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            dp[i][j] = 1;
}

int main() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> grid[i][j];
            numbers.push_back(make_tuple(grid[i][j], i, j));
        }
    }

    initialize();

    sort(numbers.begin(), numbers.end());

    int ans = 0;
    for (auto num : numbers) {
        int row, col;
        tie(ignore, row, col) = num;
        calculateDP(row, col);
        
        ans = max(ans, dp[row][col]);
    }

    cout << ans;

    return 0;
}