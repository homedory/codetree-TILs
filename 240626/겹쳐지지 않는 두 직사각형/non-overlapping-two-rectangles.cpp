#include <iostream>
#include <climits>
using namespace std;

int grid[5][5];
int n, m;

int calcSum(int left, int right, int bottom, int top) {
    int sum = 0;
    for (int i = bottom; i <= top; i++) {
        for (int j = left; j <= right; j++) {
            sum += grid[i][j];
        }
    }

    return sum;
}

int selectColumn(int bottom, int top) {
    int max_sum = INT_MIN;

    for (int i = 0; i < m; i++) {
        for (int j = i; j < m; j++) {
            max_sum = max(max_sum, calcSum(i, j, bottom, top));
        }
    }
    return max_sum;
}

int selectRow(int left, int right) {
    int max_sum = INT_MIN;

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            max_sum = max(max_sum, calcSum(left, right, i, j));
        }
    }
    return max_sum;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    int ans = INT_MIN;

    for (int bottom_1 = 0; bottom_1 < n - 1; bottom_1++) {
        for (int top_1 = bottom_1; top_1 < n - 1; top_1++) {
            for (int bottom_2 = top_1 + 1; bottom_2 < n; bottom_2++) {
                for (int top_2 = bottom_2; top_2 < n; top_2++) {
                    int sum = selectColumn(bottom_1, top_1) + selectColumn(bottom_2, top_2);
                    ans = max(ans, sum);
                }
            }
        }
    }

    for (int left_1 = 0; left_1 < m - 1; left_1++) {
        for (int right_1 = left_1; right_1 < m - 1; right_1++) {
            for (int left_2 = right_1 + 1; left_2 < m; left_2++) {
                for (int right_2 = left_2; right_2 < m; right_2++) {
                    int sum = selectRow(left_1, right_1) + selectRow(left_2, right_2);
                    ans = max(ans, sum);
                }
            }
        }
    }

    cout << ans;

    return 0;
}