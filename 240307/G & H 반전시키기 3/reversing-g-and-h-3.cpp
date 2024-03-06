#include <iostream>
#include <string>
using namespace std;

int main() {
    int N;
    string str1, str2;

    cin >> N;
    cin >> str1;
    cin >> str2;

    int ans = 0;
    for (int i = 0; i < N; i++) {
        if(str1[i] != str2[i]) {
            int cnt = 1;
            while(cnt < 4 && i < N - 1 && str1[i + 1] != str2[i + 1]) {
                cnt++;
                i++;
            }

            ans++;
        }
    }

    cout << ans;
    return 0;
}