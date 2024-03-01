#include <iostream>
using namespace std;

int main() {
    int n;

    cin >> n;

    int ans = -1;

    for (int i = n / 5; i >= 0; i--) {
        if ((n - i * 5) % 2 == 0) {
            ans = i + (n - i * 5) / 2;
            break;
        }
    }

    cout << ans;
    return 0;
}