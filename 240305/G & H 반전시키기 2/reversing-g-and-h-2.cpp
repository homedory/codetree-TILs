#include <iostream>
#include <string>
using namespace std;

int arr[1005];

int main() {
    int n;
    string str1, str2;

    cin >> n;
    cin >> str1;
    cin >> str2;

    for (int i = 0; i < n; i++) {
        if (str1[i] != str2[i]) {
            arr[i] = 1;
        }
    }

    int flip_cnt = 0;

    for (int i = n - 1; i >= 0; i--) {
        if (flip_cnt % 2 == 1) {
            arr[i] ^= 1;
        }

        if (arr[i] == 1) {
            flip_cnt++;
        }
    }

    cout << flip_cnt;
    
    return 0;
}