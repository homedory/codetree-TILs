#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

#define MAX_N 100005

int getScore(string s) {
    int R[500005];
    for (int i = 0; i <= s.length(); i++) {
        R[i] = 0;
    }

    for (int i = s.length() - 1; i >= 0; i--) {
        if (s[i] == ')') {
            R[i] = R[i + 1] + 1;
        }
        else {
            R[i] = R[i + 1];
        }
    }

    int sum = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            sum += R[i + 1];
        }
    }

    return sum;
}

bool cmp(string a, string b) {
    string concat1 = a + b;
    string concat2 = b + a;

    return getScore(concat1) >= getScore(concat2);
}

int main() {
    int n;
    string str[MAX_N];
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> str[i];
    }

    sort(str, str + n, cmp);

    string s = "";

    for (int i = 0; i < n; i++) {
        s += str[i];
    }

    cout << getScore(s);


    return 0;
}