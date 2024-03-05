#include <iostream>
using namespace std;

int n;
int arr[105];

int reverse(int n) {
    return (n == 0) ? 1 : 0;
}

void flip(int i) {
    arr[i - 1] = reverse(arr[i - 1]);
    arr[i] = reverse(arr[i]);

    if (i < n - 1) {
        arr[i + 1] = reverse(arr[i + 1]);
    }
}

int main() {   
    int ans = 0;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n - 1; i++) {
        if (arr[i] == 0) {
            flip(i + 1);
            ans++;
        }
    }

    if (arr[n - 1] == 0) {
        ans = -1;
    }

    cout << ans;
    return 0;
}