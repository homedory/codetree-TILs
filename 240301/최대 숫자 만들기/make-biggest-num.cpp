#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

#define MAX_N 50005

bool cmp(string a, string b) {
    int l = min(a.length(), b.length());

    if (a == b) {
        return true;
    }

    for (int i = 0; i < l; i++) {

        if (a[i] > b[i]) {
            return true;
        }
        else if (a[i] < b[i]) {
            return false;
        }
    }

    string concat1 = a + b;
    string concat2 = b + a;

    for (int i = 0; i < concat1.length(); i++) {
        if (concat1[i] > concat2[i]) {
            return true;
        }
        else if (concat1[i] < concat2[i]) {
            return false;
        }
    }

    return true;
}

int main() {
    int n;
    string arr[MAX_N];

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    sort(arr, arr + n, cmp);
    
    for (int i = 0; i < n; i++) {
        cout << arr[i];
    }


    return 0;
}