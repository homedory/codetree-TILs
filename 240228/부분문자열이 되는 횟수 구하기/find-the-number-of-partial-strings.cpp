#include <iostream>
#include <string>
using namespace std;

#define MAX_N 200005

int N;
int order[MAX_N];
string A, B;

bool exist[MAX_N];

void init() {
    for (int i = 0; i < N; i++) {
        exist[i] = true;
    }
}

bool IsPossible(int x) {
    init();

    for (int i = 0; i < x; i++) {
        exist[order[i] - 1] = false;
    }

    int j = 0;

    for (int i = 0; i < N; i++) {
        if (exist[i] && A[i] == B[j]) {
            j++;
        }

        if (j == B.length()) {
            return true;
        }
    }

    return false;
}

int main() {
    cin >> A;
    cin >> B;

    N = A.length();

    for (int i = 0; i < N; i++) {
        cin >> order[i];
    }

    int l = 0, r = N;
    int ans = -1;

    while(l <= r) {
        int mid = (l + r) / 2;

        if (IsPossible(mid)) {
            l = mid + 1;
            ans = mid;
        }
        else {
            r = mid - 1;
        }
    }

    cout << ans + 1;
    
    return 0;
}