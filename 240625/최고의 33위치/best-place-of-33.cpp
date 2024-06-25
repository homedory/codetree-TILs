#include <iostream>
using namespace std;

int main() {
    int N;
    int coin[21][21];

    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> coin[i][j];
        }
    }   

    int ans = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i + 2 >= N || j + 2 >= N)
                continue;

            int count = 0;
            for (int x = i; x < i + 3; x++) {
                for (int y = j; y < j + 3; y++) {
                    count += coin[x][y];
                }
            }
            ans = max(ans, count);
        }
    }

    cout << ans;

    return 0;
}