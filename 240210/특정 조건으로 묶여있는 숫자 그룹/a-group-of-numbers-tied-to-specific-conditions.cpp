#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_N 50005

int arr[MAX_N], R_Max[MAX_N], L_Max[MAX_N];

int main() {
    int N, K;

    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + N);

    int j = N - 1;
    R_Max[j] = 1;
    for (int i = N - 1; i >= 0; i--) {
        while(j - 1 >= 0 && arr[i] - arr[j - 1] <= K) {
            j--;
            R_Max[j] = max(R_Max[j + 1], i - j + 1);
        }
    }

    j = 0;
    L_Max[j] = 1;
    for (int i = 0; i < N; i++) {
        while(j + 1 < N && arr[j + 1] - arr[i] <= K) {
            j++;
            L_Max[j] = max(L_Max[j - 1], j - i + 1);
        }
    }

    int ans = 0;

    for (int i = 0; i < N - 1; i++) {
        ans = max(ans, L_Max[i] + R_Max[i + 1]);
    }

    cout << ans;


    return 0;
}