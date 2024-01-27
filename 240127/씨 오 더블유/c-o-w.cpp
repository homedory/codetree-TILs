#include <iostream>
using namespace std;

#define MAX_N 100005

int main() {
    int N;
    char arr[MAX_N], L[MAX_N], R[MAX_N];

    cin >> N;
    
    for (int i = 1; i<= N; i++) {
        cin >> arr[i];
    }

    arr[0] = 0;
    for (int i = 1; i <= N; i++) {
        if (arr[i] == 'C') {
            L[i] = L[i-1] + 1;
        }
        else {
            L[i] = L[i-1];
        }
    }

    arr[N+1] = 0;
    for (int i = N; i >= 1; i--) {
        if (arr[i] == 'W') {
            R[i] = R[i+1] + 1;
        }
        else {
            R[i] = R[i+1];
        }
    }

    long long ans = 0;

    for (int i = 2; i < N; i++) {
        if (arr[i] == 'O') {
            ans += (long long) L[i-1] * R[i+1];
        }
    }

    cout << ans;

    return 0;
}