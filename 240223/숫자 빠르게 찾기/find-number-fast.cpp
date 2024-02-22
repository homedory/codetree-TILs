#include <iostream>
using namespace std;

#define MAX_N 100005

int n, m;
int arr[MAX_N];

int find_idx(int x) {
    int idx = -1;

    int l = 1, r = n;

    while(l <= r) {
        int mid = (l + r) / 2;

        if (arr[mid] == x)
            return mid;
        
        if (arr[mid] < x) {
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }

    return -1;
}

int main() {

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        cout << find_idx(x) << "\n";
    }
    
    return 0;
}