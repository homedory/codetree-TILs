#include <iostream>
using namespace std;

int grid[20][20];

int calcArea(int left, int right, int bottom, int top) {
    for (int i = bottom; i <= top; i++) {
        for (int j = left; j <= right; j++) {
            if (grid[i][j] <= 0)
                return -1;
        }
    }

    return (right - left + 1) * (top - bottom + 1);
}

int main() {
    int n, m;

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    int ans = -1;

    for (int bottom = 0; bottom < n; bottom++) {
        for (int top = bottom; top < n; top++) {
            for (int left = 0; left < m; left++) {
                for (int right = left; right < m; right++) {
                    ans = max(ans, calcArea(left, right, bottom, top));
                }
            }
        }
    }

    cout << ans;

    return 0;
}