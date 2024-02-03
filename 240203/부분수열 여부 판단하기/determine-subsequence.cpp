#include <iostream>
using namespace std;

#define MAX_NUM 100005

int main() {
    int n, m;
    int A[MAX_NUM], B[MAX_NUM];

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> B[i];
    }

    bool ans = true;

    int i = 0;
    for (int j = 0; j < m; j++) {
        while(i < n && A[i] != B[j]) {
            i++;
        }

        if (i == n) {
            ans = false;
            break;
        }            
        i++;
    }

    cout << (ans ? "Yes" : "No");

    return 0;
}