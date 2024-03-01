#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define MAX_N 50000

vector<int> A, B;
bool check[MAX_N * 2];

int main() {
    int N;

    cin >> N; 

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        check[x] = true;
        B.push_back(x);
    }

    for (int i = 1; i <= 2 * N; i++) {
        if (!check[i]) {
            A.push_back(i);
        }
    }

    sort(A.begin(), A.end(), greater<int>());
    sort(B.begin(), B.end(), greater<int>());

    int j = 0, cnt = 0;
    for (int i = 0; i < N; i++) {
        if (B[i] < A[j]) {
            cnt++;
            j++;
        }
    }

    cout << cnt;
    
    return 0;
}