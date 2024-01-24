#include <iostream>
using namespace std;
#define MAX_N 405

int arr[MAX_N][MAX_N], prefix_sum[MAX_N][MAX_N];
int N;

int GetSum(int x1, int y1, int x2, int y2) {
    if (x1 > N || x1 < 1 || x2 > N || x2 < 1)
        return 0;
    y1 = max(y1, 1);
    y2 = min(y2, N);

    return prefix_sum[x2][y2] - prefix_sum[x1-1][y2] - prefix_sum[x2][y1-1] + prefix_sum[x1-1][y1-1];
}

int GetTotalSum(int x, int y, int k) {
    int sum = 0;
    sum += GetSum(x, y-k, x, y+k);
    for (int i = 1; i <= k; i++) {
        sum += GetSum(x - i, y - (k - i), x - i, y + (k - i));
        sum += GetSum(x + i, y - (k - i), x + i, y + (k - i));
    }

    return sum;
}

int main() {
    int K;

    cin >> N >> K;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> arr[i][j];
            prefix_sum[i][j] = prefix_sum[i-1][j] + prefix_sum[i][j-1] - prefix_sum[i-1][j-1] + arr[i][j];
        }
    }

    int ans = 0;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            ans = max(ans, GetTotalSum(i, j, K));
        }
    }

    cout << ans;

    return 0;
}