#include <iostream>
using namespace std;

#define MAX_N 100005

int main() {
    int N;
    char arr[MAX_N];
    int L[3][MAX_N], R[3][MAX_N];

    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }   


    L[0][0] = L[1][0] = L[2][0] = 0;

    for (int i = 1; i <= N; i++) {
        int x;
        if (arr[i] == 'H')
            x = 0;
        else if (arr[i] == 'S')
            x = 1;
        else if (arr[i] == 'P')
            x = 2;

        L[0][i] = L[0][i-1];
        L[1][i] = L[1][i-1];
        L[2][i] = L[2][i-1];

        L[x][i] += 1;
    }

    R[0][N+1] = R[1][N+1] = R[2][N+1] = 0;

    for (int i = N; i >= 1; i--) {
        int x;
        if (arr[i] == 'H')
            x = 0;
        else if (arr[i] == 'S')
            x = 1;
        else if (arr[i] == 'P')
            x = 2;

        R[0][i] = R[0][i+1];
        R[1][i] = R[1][i+1];
        R[2][i] = R[2][i+1];

        R[x][i] += 1;
    }

    int ans = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < 3; j++) {
            int a = (j + 1) % 3;
            int b = (j + 2) % 3;
            ans = max(ans, L[j][i] + R[a][i+1]);
            ans = max(ans, L[j][i] + R[b][i+1]);
        }
    }

    cout << ans;
    return 0;
}