#include <iostream>
using namespace std;

int compare[105][105];

int main() {
    int n, m;

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        compare[i][i] = 1;
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        compare[a][b] = 1;
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (compare[i][j])
                    continue;
                compare[i][j] = compare[i][k] && compare[k][j];
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        int cnt = 0;
        for (int j = 1; j <= n; j++) {
            if (compare[i][j] == 0 && compare[j][i] == 0)
                cnt++;
        }
        cout << cnt << "\n";
    }

    return 0;
}