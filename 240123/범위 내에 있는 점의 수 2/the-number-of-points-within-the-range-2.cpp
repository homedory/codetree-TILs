#include <iostream>
using namespace std;
#define MAX_POS 1000005

int arr[MAX_POS], prefix_num[MAX_POS];

int main() {
    int N, Q;

    cin >> N >> Q;
    
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        arr[a] = 1;
    }

    for (int i = 1; i <= MAX_POS; i++) {
        prefix_num[i] = prefix_num[i-1] + arr[i];
    }

    for (int i = 0; i < Q; i++) {
        int a, b;
        cin >> a >> b;
        cout << prefix_num[b] - prefix_num[a-1] << "\n";
    }

    return 0;
}