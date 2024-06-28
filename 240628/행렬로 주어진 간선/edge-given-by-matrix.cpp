#include <iostream>
using namespace std;

int edge[105][105];

int main() {
    int n;

    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> edge[i][j];
        }
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n ; j++) {
                if (edge[i][k] && edge[k][j])
                    edge[i][j] = 1;
                
                if (i == j)
                    edge[i][j] = 1;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << edge[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}