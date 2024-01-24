#include <iostream>
using namespace std;
#define MAX_N 1005

int arr[MAX_N][MAX_N][3], prefix_sum[MAX_N][MAX_N][3];

void PrintSum(int r1, int c1, int r2, int c2) {
    for (int i = 0; i < 3; i++) {
        cout << prefix_sum[r2][c2][i] - prefix_sum[r1-1][c2][i] - prefix_sum[r2][c1-1][i] + prefix_sum[r1-1][c1-1][i] << " ";
    }
    cout << "\n";
}

int main() {
    int n, m, k;
    int r1,r2, c1, c2;

    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char c;
            cin >> c;
            arr[i][j][c - 'a'] = 1;
            for (int l = 0; l < 3; l++) {
                prefix_sum[i][j][l] = prefix_sum[i-1][j][l] + prefix_sum[i][j-1][l] - prefix_sum[i-1][j-1][l] + arr[i][j][l];
            }
        }
    }

    for (int i = 0; i < k; i++) {
        cin >> r1 >> c1 >> r2 >> c2;
        PrintSum(r1, c1, r2, c2);
    }
    return 0;
}