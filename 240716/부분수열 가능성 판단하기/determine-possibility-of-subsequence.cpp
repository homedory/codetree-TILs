#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    vector <int> A,B;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        A.push_back(a);
    }
    for (int i = 0; i < m; i++) {
        int b;
        cin >> b;
        B.push_back(b);
    }

    vector <int> left_find, right_find;

    int index = 0;
    for (int i = 0; i < m; i++) {
        while(index < n && A[index] != B[i])
            index++;
        
        left_find.push_back(index);
    }

    index = n - 1;
    for (int i = m - 1; i >= 0; i--) {
        while(index >= 0 && A[index] != B[i])
            index--;
        
        right_find.push_back(index);
    }
    reverse(right_find.begin(), right_find.end());

    int ans = 0;
    for (int i = 0; i < m; i++) {
        if (i - 1 >= 0 && i + 1 < m) {
            if (left_find[i-1] < right_find[i+1])
                ans++;
        }
        else if (i == 0) {
            if (right_find[i+1] >= 0)
                ans++;
        }
        else if (i == m - 1) {
            if (left_find[i-1] < n)
                ans++;
        }
    }

    cout << ans;


    return 0;
}