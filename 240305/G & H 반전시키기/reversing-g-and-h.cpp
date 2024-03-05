#include <iostream>
#include <string>
using namespace std;

int arr[1005];

int main() {
    int N;
    string str1, str2;

    cin >> N;
    cin >> str1;
    cin >> str2;

    for (int i = 0; i < N; i++) {
        if (str1[i] == str2[i]) {
            arr[i + 1] = 1;
        }
    }

    int cnt = 0;
    for (int i = 1; i <= N; i++) {
        if (arr[i - 1] == 0 && arr[i] == 1) {
            cnt++;
        }
    }

    cout << cnt;
    
    return 0;
}