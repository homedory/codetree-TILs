#include <iostream>
using namespace std;
#define MAX_N 100005

int arr[MAX_N], prefix_sum[4][MAX_N];

int main() {
    int N, Q;

    cin >> N >> Q;

    for (int i = 1; i <= N; i++) {
        int x;
        cin >> x;
        for (int j = 1; j <= 3; j++) {
            prefix_sum[j][i] = prefix_sum[j][i-1];
        }
        prefix_sum[x][i] += 1;
    }

    for (int i = 0; i < Q; i++) {
        int a, b;
        cin >> a >> b;
        for (int j = 1; j <= 3; j++) {
            cout << prefix_sum[j][b] - prefix_sum[j][a-1] << " ";
        }
        cout << "\n";
    }

    return 0;
}