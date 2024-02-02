#include <iostream>
using namespace std;

#define MAX_NUM 100005

int check[MAX_NUM], arr[MAX_NUM];

int main() {
    int n;

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    int j = 0;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        while(j + 1 <= n && check[arr[j + 1]] == 0) {
            check[arr[j + 1]] = 1;
            j++;
        }

        ans = max(ans, j - i + 1);
        check[arr[i]] = 0;
    }

    cout << ans;


    return 0;
}