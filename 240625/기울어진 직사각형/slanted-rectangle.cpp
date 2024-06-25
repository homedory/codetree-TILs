#include <iostream>
using namespace std;

int n;
int grid[20][20];
int dx[4] = {-1, -1, 1, 1};
int dy[4] = {1, -1, -1, 1};

int calcSum(int x, int y, int height, int width) {
    int sum = 0;

    for (int i = 0; i < height; i++) {
        x += dx[0];
        y += dy[0];
        if (x < 0 || x > n || y < 0 || y > n)
            return 0;
        
        sum += grid[x][y];
    }

    for (int i = 0; i < width; i++) {
        x += dx[1];
        y += dy[1];
        if (x < 0 || x > n || y < 0 || y > n)
            return 0;
        
        sum += grid[x][y];
    }

    for (int i = 0; i < height; i++) {
        x += dx[2];
        y += dy[2];
        if (x < 0 || x > n || y < 0 || y > n)
            return 0;
        
        sum += grid[x][y];
    }

    for (int i = 0; i < width; i++) {
        x += dx[3];
        y += dy[3];
        if (x < 0 || x > n || y < 0 || y > n)
            return 0;
        
        sum += grid[x][y];
    }

    return sum;
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int h = 1; h <= i; h++) {
                for (int w = 1; w <= i + 1 - h; w++) {
                    ans = max(ans, calcSum(i, j, h, w));
                }
            }
        }
    }

    cout << ans;
    
    return 0;
}