#include <iostream>
using namespace std;

#define MAX_N 100005

int A[MAX_N], B[MAX_N], L[MAX_N], R[MAX_N];

int main() {
    int n, m;

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> B[i];
    }

    int j = 1;
    for (int i = 1; i <= m; i++) {
        while(j + 1 <= n && A[j] != B[i]) {
            j++;
        }
        if (A[j] == B[i]) {
            L[i] = j;
            j++;
        }
        else {
            L[i] = MAX_N;
            j = MAX_N;
        }
    }

    j = n;
    for (int i = m; i > 0; i--) {
        while(j - 1 > 0 && A[j] != B[i]) {
            j--;
        }
        if (A[j] == B[i]) {
            R[i] = j;
            j--;
        }
        else {
            R[i] = 0;
            j = 0;
        }
    }

    R[m + 1] = MAX_N;

    int ans = 0;

    for (int i = 1; i <= m; i++) {
        if (L[i - 1] < R[i + 1]) {
            ans++;
        }
    }

    cout << ans;


    return 0;
}