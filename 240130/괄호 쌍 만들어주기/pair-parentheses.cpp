#include <iostream>
#include <string>
using namespace std;

#define MAX_N 100005

char arr[MAX_N];
int L[MAX_N], R[MAX_N];

int main() {
    string str;

    cin >> str;

    int n = str.length();

    R[n - 1] = 0;
    for (int i = n - 2; i >= 0; i--) {
        if (str[i+1] == ')' && str[i] == ')') {
            R[i] = R[i+1] + 1;
        }
        else {
            R[i] = R[i+1];
        }
    }

    long long ans = 0;
    
    for (int i = 1; i < n - 2; i++) {
        if (str[i-1] == '(' && str[i] == '(') {
            ans += R[i + 1];
        }
    }

    cout << ans;

    return 0;
}